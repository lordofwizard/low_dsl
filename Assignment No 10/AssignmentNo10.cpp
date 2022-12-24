#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool are_pair(char opening,char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}
bool are_balanced(string exp)
{
    stack<char>  S;
    for(int i =0; i<exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(S.empty() || !are_pair(S.top(),exp[i]))
                return false;
            else
                S.pop();
        }
    }
    if (S.empty() == true) return true;
    else return false;
}

int main()
{
    string expession;
    cout<<"Enter an expession:  ";
    cin>>expession;
    if(are_balanced(expession)) cout<<"Balanced\n";
    else cout<<"Not Balanced\n";
}

