#include <stdlib.h>
#include <string.h>

//Type
typedef struct gVec {
	void **buff_ptr; //A pointer to the User's buffer's pointer.
	size_t capacity, size, block_size;
}gVec;

//This function initializes a vector struct with provided argumants.
//1st parameter a pointer to the struct.
//2nd parameter a pointer to the buffer's pointer.
int gVecInit(gVec *vec, void **buff_ptr, size_t size, size_t block_size);

//This function frees the buffer and adjusts the values of the struct to their uninitialized values.
//1st parameter a pointer to the struct.
int gVecEmpty(gVec *vec);

//This function makes sure if there is a need of extending capacity and increases the size. So use this function before giving the value.
int gVecPushBack(gVec *vec);

//This function removes the value at the given index and decreases the size.
//2nd parameter is the index of the value.
int gVecRemove(gVec *vec, int index);

//This function an empty space on specified index on there by moving the values to the right for our purpose of inserting there a value.
//2nd parameter is the index of the spot we wan't to make there a space.
int gVecInsert(gVec *vec, int index);

//This function reverses the given vector's content.
int gVecReverse(gVec *vec);

//This function gets the elements of source between the range of start and end indices and copies them to the target,
//3rd parameter is the start index of range. Start index's element is tuned in sub vector.
//4th parameter is the end index of range. End index's element isn't tuned in sub vector. 
int gVecSubVec(gVec *target, gVec *source, int start, int end);

//This macro converts the vector's buffer to char* for the purpose of change the position of the pointer.
#define BYTE_BUFF(vec) ((char*)*vec->buff_ptr)
