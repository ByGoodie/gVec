#include <stdlib.h>
#include <string.h>

/// @brief A generic vector struct.
typedef struct gVec {
	/// @brief points to the user buffer.
	void **buff_ptr; 
	/// @brief capacity of the vector.
	size_t capacity;
	/// @brief size of the vector.
	size_t size;
	/// @brief size of a block.
	size_t block_size;
} gVec;

/// @brief Initializes the vector.
/// @param vec A pointer to the vector.
/// @param buff_ptr A pointer to the user buffer.
/// @param size Size of the vector.
/// @param block_size Size of a block.
/// @return 0 on success, -1 on failure.
int gVecInit(gVec *vec, void **buff_ptr, size_t size, size_t block_size);

/// @brief Frees the vector.
/// @param vec A pointer to the vector.
/// @return 0 on success, -1 on failure.
int gVecEmpty(gVec *vec);

/// @brief Increases the capacity of the vector if needed. Must be used before pushing a value.
/// @param vec A pointer to the vector.
/// @return 0 on success, -1 on failure.
int gVecPushBack(gVec *vec);

/// @brief Removes the value at the given index and decreases the size.
/// @param vec A pointer to the vector.
/// @param index Index of the value to remove.
/// @return 0 on success, -1 on failure.
int gVecRemove(gVec *vec, int index);

/// @brief Inserts an empty block on specified index on there by moving the values to the right.
/// @param vec A pointer to the vector.
/// @param index The index to insert the empty block.
/// @return 0 on success, -1 on failure.
int gVecInsert(gVec *vec, int index);

/// @brief Reverses the given vector.
/// @param vec A pointer to the vector.
/// @return 0 on success, -1 on failure.
int gVecReverse(gVec *vec);

/// @brief Cuts a sub vector from the given vector.
/// @param target A pointer to the target vector.
/// @param source A pointer to the source vector.
/// @param start The start index of the range.
/// @param end The end index of the range.
/// @return 0 on success, -1 on failure. 
int gVecSubVec(gVec *target, gVec *source, int start, int end);

//This macro converts the vector's buffer to char* for the purpose of change the position of the pointer.
#define BYTE_BUFF(vec) ((char*)*vec->buff_ptr) // Casts the vector buffer to char*