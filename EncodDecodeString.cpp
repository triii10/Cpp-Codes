// An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
// original string: abbbababbbababbbab 
// encoded string : "3[a3[b]1[ab]]".

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

// Output:
// For each test case in a new line print the required decoded string.

// Constraints:
// 1<=T<=10
// 1<=length of the string <=30

// Example:
// Input:
// 2
// 1[b]
// 3[b2[ca]]

// Output:
// b
// bcacabcacabcaca


#include<bits/stdc++.h>
using namespace std;

string parsedString(string S)
{
    if(S.empty())
        return "";
    
    // @no --> stores the number of times the string insider the bracket will be repeated
    // @last --> stores the index of the last character in the string
    int no, last = S.length()-1;        
    
    // @number --> stores "@no" in string format to be converted later and stored in "@no"
    // @toParse --> stores the string inside the bracket that is to be recursively parsed
    // @parsed --> the string is parsed recursively and stored in this variable
    string number = "", toParse, parsed = "";
    
    // Iterating through the string checking for each character
    for(int i = 0;i < S.length();i++)
    {
        // If the character is an alphabet, it is pushed into the parsed string
        if(S[i] >= 'a' && S[i] <= 'z')
            parsed += S[i];
        
        // If the character is a number, it is pushed into the @number variable
        else if(S[i] >= '0' && S[i] <= '9')
            number += S[i];
        
        // If it is nether a number, nor a alphabet, it must be an opening square bracket
        else
        {
            //@toParse will extract the substring that is enclosed within the square bracket
            toParse = S.substr(i+1, last -i- 1);
            
            //@no will store the @number in integer format
            no = stoi(number);
            
            // @ins --> the parsed string inside the square brackets that as to be repeated
            string ins = parsedString(toParse);
            
            while(no--)
                // Adding the @ins to the @parsed string
                parsed += ins;
            
            // The string is completely parsed, so return it
            return parsed;
        }
    }
    
    // Return the parsed string
    return parsed;
}

int main() {
    
    // @t --> number of test cases
    int t;
    cin>>t;
    
    
    while(t--)
    {
        // @s --> input string
        string s;
        cin>>s;
        
        // Printing the parsed string
        cout<<parsedString(s)<<endl;
    }
    
    return 0;
}
