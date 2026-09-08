#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  char input[80];
  char strip_inp[80];
  int count = 0;
  bool palindrome = true;
  
  cout << "Enter your text: ";
  cin.get(input, 80);

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

  for (int i = 0; i < count / 2; i++) {
    if (strip_inp[i] != strip_inp[count - i]) {
      palindrome = false;
      break;
    }
  }

  if (palindrome) {
    cout << "Palindrome.";
  }
  else {
    cout << "Not a palindrome.";
  }
}
