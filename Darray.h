#ifndef DARRAY_H
#include <stdlib.h>

#define DARRAY_H
#define VECTOR_INIT_CAPACITY 1000

// @param size: the number of element in the array
// @param capacity: number of open space in the array
// @param data: storing the element
typedef struct {
    int size;
    int capacity;
    int *data;
} Vector;

// Initialize a dynamic array with VECTOR_INIT_CAPACITY capacity and 0 element
// @param *vector: the pointer to a Vector variable that haven't been initialize
// @notice if you try to input the vector that have already been initialize then it doesn't do anything
void initVector(Vector *vector) {
    vector->size = 0;
    vector->capacity = VECTOR_INIT_CAPACITY;

    // allocate memory to data
    vector->data = (int *)calloc(VECTOR_INIT_CAPACITY, sizeof(int));
}

// Insert an element to the end of the array
// @param *vector: the pointer to a Vector variable that have been initialized
// @param element: the element that is going to be added into the array
void insertEnd(Vector *vector, int element) {
    if (vector->size == vector->capacity) {
        vector->data = (int *)realloc(vector->data, ( vector->capacity * 2 ) * sizeof(int));
        vector->capacity *= 2;
    }
    vector->data[vector->size] = element;
    vector->size++;
}

// Insert an element to the beginning of the array
// @param *vector: the pointer to a Vector variable that have been initialized
// @param element: the element that is going to be added into the array
void insertStart(Vector *vector, int element) {
    if (vector->size == vector->capacity) {
        vector->data = (int *)realloc(vector->data, ( vector->capacity * 2 ) * sizeof(int));
        vector->capacity *= 2;
    }

    vector->data[0] = element;
    vector->size++;
}

// Free the data from the array
// @param *vector: the pointer to a Vector variable that have been initialized
// @notice If you call on an array that haven't been initialized it will give back error
void vectorFree(Vector *vector) {
    free(vector->data);
}

// Set the element from the array
// @dev set the element from the array with an unsigned integer index
// @param *vector: the pointer to a Vector variable that have been initialized
// @param index: the index to get back the Vector
void vectorSet(Vector *vector, unsigned index, int element) {
    while(index > vector->size - 1)
        insertEnd(vector, 0);
    vector->data[index] = element;
}

// Get back the element from the array
// @dev get back the element from the array with an unsigned integer index
// @param *vector: the pointer to a Vector variable that have been initialized
// @param index: the index to get back the Vector
// @return a int that assign to that array location
int vectorGet(Vector *vector, unsigned index) {
    if (index < vector->size && index >=0)
        return vector->data[index];
    printf("Error: Vector is out of bound\n");
    exit(1);
}

// Return the number of element in the vector
// @param *vector: the pointer to a Vector variable that have been initialized
// @return the number of the element in array have been used
int vectorLength(Vector *vector) {
    return vector->size;
}

#endif /* end of include guard */
