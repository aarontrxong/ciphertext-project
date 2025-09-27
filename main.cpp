#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

// Function to reverse the string 
std::string reverseString(const std::string& text) {
    std::string result = text;
    std::reverse(result.begin(), result.end());
    return result;
}

// Encrypt function: reverse the string
std::string encrypt(const std::string& plainText) {
    return reverseString(plainText);
}

// Decrypt function: reverse the string back
std::string decrypt(const std::string& cipherText) {
    return reverseString(cipherText);
}

// Function to encrypt file
void encryptFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream InFile(inputFile);
    std::ofstream OutFile(outputFile);

    if (!InFile) {
        std::cout << "Error: Cannot open input file.\n";
        return;
    }
    if (!OutFile) {
        std::cout << "Error: Cannot open output file.\n";
        return;
    }

    std::string line;
    while (getline(InFile, line)) {
        OutFile << encrypt(line) << "\n";
    }

    InFile.close();
    OutFile.close();
    std::cout << "Encryption complete.\n";
}

// Function to decrypt file
void decryptFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream InFile(inputFile);
    std::ofstream OutFile(outputFile);

    if (!InFile) {
        std::cout << "Error: Cannot open input file.\n";
        return;
    }
    if (!OutFile) {
        std::cout << "Error: Cannot open output file.\n";
        return;
    }

    std::string line;
    while (getline(InFile, line)) {
        OutFile << decrypt(line) << "\n";
    }

    InFile.close();
    OutFile.close();
    std::cout << "Decryption complete.\n";
}

// User Interaction
int main() {
    std::cout << " Encryption/Decryption " << "\n";
    std::cout << "1. Encrypt a file " << "\n";
    std::cout << "2. Decrypt a file " << "\n";
    std::cout << "Enter option (1 or 2): " << "\n";

    int option;
    std::cin >> option;

    std::string inputFile;
    std::string outputFile;

    std::cout << "Enter input filename: " << "\n";
    std::cin >> inputFile;
    std::cout << "Enter output filename: " << "\n";
    std::cin >> outputFile;

    if (option == 1) {
        encryptFile(inputFile, outputFile);
    } else if (option == 2) {
        decryptFile(inputFile, outputFile);
    } else {
        std::cout << "Invalid option! Exiting." << "\n";
    }

    return 0;
}