#include "include/gVec.h"

int gVecInit(gVec *vec, void **buff_ptr, size_t size, size_t block_size) {
	if (vec == NULL || buff_ptr == NULL || size < 0) return -1;
	vec->buff_ptr = buff_ptr;
	vec->size = size;
	vec->block_size = block_size;

	//Finding the nearest and greater 2^n than the size.
	int i;
	for (i = 1; size != 1 && size != 0; i++) {
		size >>= 1;
	} 
	vec->capacity = 1 << i;	
	if ((*vec->buff_ptr = malloc(block_size * vec->capacity)) == NULL) return -1;
	return 0;
}

int gVecEmpty(gVec *vec) {
	if (vec == NULL || vec->buff_ptr == NULL || *vec->buff_ptr == NULL) return -1;
	free(*vec->buff_ptr);
	*vec->buff_ptr = NULL;
	vec->size = 0;
	vec->capacity = 0;
	return 0;
}

int gVecPushBack(gVec *vec) {
	if (vec == NULL || vec->buff_ptr == NULL || *vec->buff_ptr == NULL || vec->capacity == 0) return -1;
	vec->size++;

	//Allocating more memory for purpose of holding more values.
	if (vec->size > vec->capacity) {
		vec->capacity <<= 1;
		void *temp = malloc(vec->capacity * vec->block_size);
		if (temp == NULL) {
			vec->capacity >>= 1;
			return -1;
		}
		memcpy(temp, *vec->buff_ptr, (vec->capacity >> 1) * vec->block_size);
		free(*vec->buff_ptr);
		*vec->buff_ptr = temp;
	}
	return 0;
}

int gVecRemove(gVec *vec, int index) {
	if (vec == NULL || vec->buff_ptr == NULL || *vec->buff_ptr == NULL || vec->capacity == 0 || (vec->size <= index) || (index < 0)) return -1;
	vec->size--;

	//Moving the following memory of index's memory to the index's memory.
	memmove(BYTE_BUFF(vec) + (index * vec->block_size), BYTE_BUFF(vec) + ((index + 1) * vec->block_size), (vec->size - index) * vec->block_size);
	return 0;
}

int gVecInsert(gVec *vec, int index) {
	if (vec == NULL || vec->buff_ptr == NULL || *vec->buff_ptr == NULL || vec->capacity == 0 || (vec->size <= index) || (index < 0)) return -1;
	gVecPushBack(vec);

	//Moving the memory on the specified index to the following memory of the specified index.
	memmove(BYTE_BUFF(vec) + ((index + 1) * vec->block_size), BYTE_BUFF(vec) + (index * vec->block_size), (vec->size - index - 1) * vec->block_size);
	return 0;
}

int gVecReverse(gVec *vec) {
	if (vec == NULL || vec->buff_ptr == NULL || *vec->buff_ptr == NULL || vec->capacity == 0) return -1;
	
	void *temp = malloc(vec->block_size);
	if (temp == NULL) return -1;

	//Used memcpy to swap because of the unknown type of the values.
	for (int i = 0; i < vec->size / 2; i++) {
		memcpy(temp, BYTE_BUFF(vec) + i * vec->block_size, vec->block_size);
		memcpy(BYTE_BUFF(vec) + i * vec->block_size, BYTE_BUFF(vec) + (vec->size - i - 1) * vec->block_size, vec->block_size);
		memcpy(BYTE_BUFF(vec) + (vec->size - i - 1) * vec->block_size, temp, vec->block_size);
	}
	free(temp);
	return 0;
}

int gVecSubVec(gVec *target, gVec *source, int start, int end) {
	if (target == NULL || source == NULL || target->buff_ptr == NULL || source->buff_ptr == NULL || target->capacity == 0 || source->capacity == 0 || start < 0 || end < 0 || start > source->size || end > source->size || target->block_size != source->block_size) return -1;
	if (gVecEmpty(target) == -1) return -1;
	if (gVecInit(target, target->buff_ptr, end - start, target->block_size) == -1) return -1;

	memcpy(*target->buff_ptr, BYTE_BUFF(source) + start * source->block_size, (end - start) * target->block_size);
	
	return 0;
}