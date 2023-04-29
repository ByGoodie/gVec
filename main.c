#include "gVec.h"
#include <stdio.h>

int main(void) {
	gVec vec, subvec;
	int *values, *subvalues, in, start, end;
	if (gVecInit(&vec, (void**)&values, 0, sizeof(int)) == -1) return -1;
	if (gVecInit(&subvec, (void**)&subvalues, 0, sizeof(int)) == -1) return -1;
	printf("In Start\n");
	printf("Length of the Vector: ");
	scanf("%d", &in);
	for (int i = 0; i < in; i++) {
		gVecPushBack(&vec);
		scanf("%d", values + i);
	}
	printf("Start: ");
	scanf("%d", &start);
	printf("End: ");
	scanf("%d", &end);
		
	printf("Out Start\n");
	if (gVecSubVec(&subvec, &vec, start, end) == -1) printf("Error");
	gVecReverse(&subvec);
	for (int i = 0; i < subvec.size; i++) {
		printf("%d, ", subvalues[i]);
	}

	printf("Capacity: %d\n", vec.capacity);
	gVecEmpty(&vec);
	gVecEmpty(&subvec);
	return 0;
}
