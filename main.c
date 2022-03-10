// Example code to explore process memory using GDB
// Make sure to compile without optimizations

#include <stdio.h>
#include <stdlib.h>

// Some message to be repeated as a "marker" in memory so it can be easily found
const char message[] = "HEAP DATA!";

const int HEAP_SIZE = 128;
const int STACK_SIZE = 128;

void* allocate_memory(void) {
    const char local_message[] = "INSIDE ALLOCATE_MEMORY!";
    char stack_data[STACK_SIZE];
    for(int i = 0; i < STACK_SIZE; ++i) {
        stack_data[i] = local_message[i % sizeof(local_message)];
    }

    char* heap_data = malloc(sizeof(char) * HEAP_SIZE);
    for(int i = 0; i < HEAP_SIZE; ++i) {;
        heap_data[i] = message[i % sizeof(message)];
    }

    printf("Address of allocated memory: %p\n", heap_data);

    // Place breakpoint here and run GDB commands
    return heap_data;
};

int main(const int argv, const char** argc) {
    const char local_message[] = "DATA FROM MAIN!";
    char stack_data[STACK_SIZE];
    for(int i = 0; i < STACK_SIZE; ++i) {
        stack_data[i] = local_message[i % sizeof(local_message)];
    }

    void* heap_data = allocate_memory();

    printf("Press enter to continue\n");
    getchar();

    free(heap_data);
    return 0;
}