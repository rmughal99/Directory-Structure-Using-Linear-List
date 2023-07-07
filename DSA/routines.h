#include <iostream>
#include<cstring>
using namespace std;
const int MAX_DISK_SPACE = 64; // Maximum available disk space

struct block {
    short blockId;
    struct block* nextB;
};

struct fNode {
    char File[20];
    char Extn[5];
    struct block* start;
    struct block* end;
    short fSize; // no. of blocks
    struct fNode* next;
};
class Directory {
private:
    struct fNode* head; // head of the linked list
public:
    Directory() {
        head = nullptr; // Initialize the head to nullptr (empty list)
    }
    // Add a file to the directory
    void addFile(const char* fileName, const char* fileExt, int fileSize);
    // Display the files in the directory
    void displayFiles();
    // Search for a particular file in the directory
    struct fNode* searchFile(const char* fileName, const char* fileExt);
    // Simulate disk allocation to a new file
    void allocateDiskSpace(const char* fileName, int fileSize);
    // Delete a specific file from the directory structure
    void deleteFile(const char* fileName, const char* fileExt);
    // Deallocate the disk space for the deleted file
    void deallocateDiskSpace(struct fNode* file);
    // Create and insert a new file at the appropriate location in the directory
    void createAndInsertFile(const char* fileName, const char* fileExt, int fileSize);
    // Display the status of the disk (availability of blocks)
    void displayDiskStatus();


};