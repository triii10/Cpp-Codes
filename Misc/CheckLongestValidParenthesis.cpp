/**
 * * Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.
 * * Input:
 * *    First line contains number of test cases T.  
 * *    Each test case have one line string S of character '(' and ')' of length  N.
 * ! Constraints:
 * !    1 <= T<= 500
 * !    1 <= N<= 105
 * * Example:
 * *    Input:
 * *    2
 * *    ((()
 * *    )()())
 * *    Output:
 * *    2
 * *    4
 * * Explanation:
 * *    Testcase 1: Longest valid balanced parantheses is () and its length is 2
*/

#include<bits/stdc++.h>
using namespace std;

/** 
 * longestValidParentheses
 * * This method calculates the length of the longest valid parantheses in the input string and returns the value
 * @param s input string to be parsed
 * * Using a stack implemented through a vector, valid parantheses are parsed.
 * * After successful completion of the loop, the stack will contain "indices" of only those paranteses which do not have a valid pair
 * * Between two consecutive elements of the stack, are the valid parantheses.
*/
int longestValidParentheses(string s)
{
    vector<int> st;     // Implementing a stack using a vector
    int top = -1;       // @top pointer for the top of the stack
    s = ')' + s + '(';  // The string is modified with two unmatched pairs as endcases
    for (int i = 0; i < s.length(); i++)
    {
        // If we get an opening bracket, '(' , the index is pushed into the stack
        if (s[i] == '(')
        {
            st.push_back(i);
            top++;
        }

        // If we get a closing bracket, ')' , the top of the stack is checked.
        else
        {
            // If the top of the stack has an opening bracket, then they form a valid pair, so it is popped.
            if (top >= 0 && s[st[top]] == '(')
            {
                st.pop_back();
                top--;
            }

            // If the top is not an opening bracket, then it is an unmatched pair, so the index is pushed into the stack.
            else
            {
                st.push_back(i);
                top++;
            }
        }
    }

    // Calculating the length of valid parantheses in the string

    int l = 0;
    for (int i = 0; i < st.size() - 1; i++)
    {
        int temp = st[i + 1] - st[i] - 1;
        if (temp > l)
            l = temp;
    }

    // Returning the maximum length
    return l;
}

// * The driver function for the usecase
int main()
{

    // The number of test cases "t"
    int t;
    cin>>t;
    while(t--)
    {
        string inputString;
        cin>>inputString;

        cout<<"The size of the longest valid parantheses substring is "
        <<longestValidParentheses(inputString)
        <<endl;
    }
    return 0;
}