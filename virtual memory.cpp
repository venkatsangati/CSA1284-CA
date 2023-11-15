#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096 
typedef struct {
    int page_number;
    char data[PAGE_SIZE];
} Page;

Page* virtual_memory[256]; 


void initializeVirtualMemory() {
    for (int i = 0; i < 256; i++) {
        virtual_memory[i] = NULL; 
    }
}


int allocatePage() {
    for (int i = 0; i < 256; i++) {
        if (virtual_memory[i] == NULL) {
            virtual_memory[i] = (Page*)malloc(sizeof(Page));
            virtual_memory[i]->page_number = i;
            return i;
        }
    }
    return -1; 
}


void accessPage(int page_number, char* data) 
{

    if (virtual_memory[page_number] != NULL) {
        
        for (int i = 0; i < PAGE_SIZE; i++) {
            virtual_memory[page_number]->data[i] = data[i];
        }
        printf("Accessed page %d in virtual memory.\n", page_number);
    } else {
        printf("Page %d is not allocated in virtual memory.\n", page_number);
    }

}

int main() {
    initializeVirtualMemory();

    int page1 = allocatePage();
    int page2 = allocatePage();

    char data1[PAGE_SIZE] = "This is data for page 1.";
    char data2[PAGE_SIZE] = "Data for page 2.";

    accessPage(page1, data1);
    accessPage(page2, data2);

    return 0;
}

