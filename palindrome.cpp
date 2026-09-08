/*
Elijah Chan 9/8/2026
Reads in a series of characters up to 80 characters long and returns if it is a palindrome or not.
*/
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  char input[80];
  char strip_inp[80];
  int count = 0;
  bool palindrome = true;

  //Takes the user's inputted characters and puts them into the input char list.
  cout << "Enter your text: ";
  cin.get(input, 80);

  //Goes through every character in the input and adds a lowercase version to the strip_inp char list if it is an alphanumeric character.
  //https://www.geeksforgeeks.org/c/isalnum-function-c-language/
  //https://www.geeksforgeeks.org/cpp/tolower-function-in-cpp/
  for (int i = 0; i < 80; i++) {
    char ch = input[i];

    if (ch != '\0') {
      if (isalnum(ch)) {
	strip_inp[count] = (char)tolower(ch);
	count++;
      }
    }
    else {      
      count--;
      break;
    }
  }

  //Checks through the strip_inp char list and makes palindrome false if it isn't a palindrome.
  for (int i = 0; i < count / 2; i++) {
    if (strip_inp[i] != strip_inp[count - i]) {
      palindrome = false;
      break;
    }
  }

  //Outputs if the input was a palindrome or not.
  if (palindrome) {
    cout << "Palindrome.";
  }
  else {
    cout << "Not a palindrome.";
  }
}
