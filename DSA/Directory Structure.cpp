#include"routines implementation.cpp";

int main() {
 Directory dir;
 char fileName[20], fileExt[5];
 int fileSize;
 int choice;
 do {
     std::cout << "\t\t\t\t*_*_*_*_*_*_*_*_*_Directory Structure*_*_*_*_*_*_*_*_*_\n\n\t\t\tMain Menu:\n";
     std::cout << "\t\t\t\t1. Add a file to the directory" << std::endl;
     std::cout << "\t\t\t\t2. Display the files in the directory" << std::endl;
     std::cout << "\t\t\t\t3. Search for a file in the directory" << std::endl;
     std::cout << "\t\t\t\t4. Allocate disk space to a new file" << std::endl;
     std::cout << "\t\t\t\t5. Delete a file from the directory" << std::endl;
     std::cout << "\t\t\t\t6. Create and insert a new file at the appropriate location in the directory" << std::endl;
     std::cout << "\t\t\t\t7. Display the status of the disk" << std::endl;
     std::cout << "\t\t\t\t8. Go back to main menu" << std::endl;
     std::cout << "\t\t\t\t9. Exit" << std::endl;
     std::cout << "\t\t\t\t10. Credits" << std::endl;
     std::cout << "\t\t\tEnter your choice: ";
     std::cin >> choice;

     switch (choice) {
     case 1:
         system("cls");
         std::cout << "Enter the file name: ";
         std::cin >> fileName;
         std::cout << "Enter the file extension: ";
         std::cin >> fileExt;
         std::cout << "Enter the file size: ";
         std::cin >> fileSize;
         dir.addFile(fileName, fileExt, fileSize);
         system("pause");
         system("cls");
         break;
     case 2:
         system("cls");
         dir.displayFiles();
         system("pause");
         system("cls");
         break;
     case 3:
         system("cls");
         std::cout << "Enter the file name: ";
         std::cin >> fileName;
         std::cout << "Enter the file extension: ";
         std::cin >> fileExt;
         if (dir.searchFile(fileName, fileExt) != nullptr) {
             std::cout << "File " << fileName << "." << fileExt << " found in the directory." << std::endl;
         }
         else {
             std::cout << "File " << fileName << "." << fileExt << " not found in the directory." << std::endl;
         }
         system("pause");
         system("cls");
         break;
     case 4:
         system("cls");
         std::cout << "Enter the file name: ";
         std::cin >> fileName;
         std::cout << "Enter the file extension: ";
         std::cin >> fileExt;
         std::cout << "Enter the file size: ";
         std::cin >> fileSize;
         dir.allocateDiskSpace(fileName, fileSize);
         system("pause");
         system("cls");
         break;
     case 5:
         system("cls");
         std::cout << "Enter the file name: ";
         std::cin >> fileName;
         std::cout << "Enter the file extension: ";
         std::cin >> fileExt;
         dir.deleteFile(fileName, fileExt);
         system("pause");
         system("cls");
         break;
     case 6:
         system("cls");
         std::cout << "Enter the file name: ";
         std::cin >> fileName;
         std::cout << "Enter the file extension: ";
         std::cin >> fileExt;
         std::cout << "Enter the file size: ";
         std::cin >> fileSize;
         dir.createAndInsertFile(fileName, fileExt, fileSize);
         system("pause");
         system("cls");
         break;
     case 7:
         system("cls");
         dir.displayDiskStatus();
         system("pause");
         system("cls");
         break;
     case 8:
         system("cls");
         system("pause");
         system("cls");
         main();
         break;
     case 9:
         exit(0);
         break;
     case 10:
         system("cls");
         std::cout << "Created By: \n\t\t Muhammad Rohaan (21F-9126)\n";
         system("pause");
         system("cls");
         break;
     default:
         std::cout << "Invalid choice!" << std::endl;
         break;
     }
} while (choice != 11);

   






    system("pause>0");
    return 0;
}
