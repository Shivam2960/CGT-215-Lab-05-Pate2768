#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function that translates one character
char translateCharacter(char character, const vector<char>& codeTable)
{
    // Check if the character is a capital letter
    if (character >= 65 && character <= 90)
    {
		return codeTable[character - 65]; // Subtract 65 to get the index in the code table and return the corresponding character
    }

    // Check if the character is a lowercase letter
    else if (character >= 97 && character <= 122)
    {
		char upperCaseLetter = character - 32; // Convert to uppercase by subtracting 32

		char upperCaseCode = codeTable[upperCaseLetter - 65]; // Get the corresponding code for the uppercase letter

		return upperCaseCode + 32; // Convert back to lowercase by adding 32 and return the corresponding character
    }

    // If number, spaces, symbols, etc, return the letter unmodified
    else
    {
        return character;
    }
}

int main()
{
	// Cypher translation table used for the translation of letters
    vector<char> codeTable =
    {
        'V', 'F', 'X', 'B', 'L', 'I', 'T', 'Z', 'J',
        'R', 'P', 'H', 'D', 'K', 'N', 'O', 'W', 'S',
        'G', 'U', 'Y', 'Q', 'M', 'A', 'C', 'E'
    };

    string text;

    cout << "Input text to cypher: ";

    // Reads the entire line, including spaces
    getline(cin, text);

    cout << "Encoded message: ";

    // Go through every character in the string
    for (int i = 0; i < text.length(); i++)
    {
		// Call the translateCharacter function to get the corresponding character from the code table and print it
        cout << translateCharacter(text[i], codeTable);
    }

    cout << endl;

    return 0;
}