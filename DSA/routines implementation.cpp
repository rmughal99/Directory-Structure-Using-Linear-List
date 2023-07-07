#include"routines.h"

void Directory::addFile(const char* fileName, const char* fileExt, int fileSize) {
        struct fNode* newNode = new struct fNode;
        strcpy_s(newNode->File, fileName);
        strcpy_s(newNode->Extn, fileExt);
        newNode->start = nullptr;
        newNode->end = nullptr;
        newNode->fSize = fileSize;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            struct fNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

  
void Directory::displayFiles() {
        struct fNode* temp = head;
        if (temp == nullptr) {
            std::cout << "Directory is empty." << std::endl;
        }
        else {
            while (temp != nullptr) {
                std::cout << temp->File << "." << temp->Extn << std::endl;
                temp = temp->next;
            }
        }
    }

    
    struct fNode* Directory::searchFile(const char* fileName, const char* fileExt) {
        struct fNode* temp = head;
        while (temp != nullptr) {
            if (strcmp(temp->File, fileName) == 0 && strcmp(temp->Extn, fileExt) == 0) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

   
    void Directory::allocateDiskSpace(const char* fileName, int fileSize) {
        int availableSpace = MAX_DISK_SPACE;
        struct fNode* temp = head;

        while (temp != nullptr) {
            availableSpace -= temp->fSize;
            temp = temp->next;
        }

        if (fileSize <= availableSpace) {
            std::cout << "Disk space allocated for file " << fileName << " with size " << fileSize << "." << std::endl;
        }
        else {
            std::cout << "Error: Insufficient disk space for file " << fileName << " with size " << fileSize << "." << std::endl;
        }
    }

   
    void Directory::deleteFile(const char* fileName, const char* fileExt) {
        struct fNode* prev = nullptr;
        struct fNode* curr = head;

        while (curr != nullptr) {
            if (strcmp(curr->File, fileName) == 0 && strcmp(curr->Extn, fileExt) == 0) {
                if (prev == nullptr) {
                    head = curr->next;
                }
                else {
                    prev->next = curr->next;
                }

                deallocateDiskSpace(curr);
                delete curr;

                std::cout << "File " << fileName << "." << fileExt << " deleted from the directory." << std::endl;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        std::cout << "File " << fileName << "." << fileExt << " not found in the directory." << std::endl;
    }

    
    void Directory::deallocateDiskSpace(struct fNode* file) {
        struct block* curr = file->start;
        while (curr != nullptr) {
            struct block* temp = curr;
            curr = curr->nextB;
            delete temp;
        }
    }

   
    void Directory::createAndInsertFile(const char* fileName, const char* fileExt, int fileSize) {
        struct fNode* newNode = new struct fNode;
        strcpy_s(newNode->File, fileName);
        strcpy_s(newNode->Extn, fileExt);
        newNode->start = nullptr;
        newNode->end = nullptr;
        newNode->fSize = fileSize;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else if (strcmp(newNode->File, head->File) < 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            struct fNode* prev = head;
            struct fNode* curr = head->next;

            while (curr != nullptr && strcmp(newNode->File, curr->File) > 0) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = newNode;
            newNode->next = curr;
        }

        allocateDiskSpace(fileName, fileSize);
    }


 
    void Directory::displayDiskStatus() {
        std::cout << "Disk Status:" << std::endl;
        bool isAllocated[MAX_DISK_SPACE] = { false }; // Array to track allocated blocks

        struct fNode* temp = head;
        while (temp != nullptr) {
            struct block* blockTemp = temp->start;
            while (blockTemp != nullptr) {
                isAllocated[blockTemp->blockId] = true;
                blockTemp = blockTemp->nextB;
            }
            temp = temp->next;
        }

        for (int i = 0; i < MAX_DISK_SPACE; i++) {
            std::cout << (i + 1) << ": ";
            if (isAllocated[i]) {
                std::cout << "Allocated";
            }
            else {
                std::cout << "Free";
            }
            std::cout << std::endl;
        }
    }
