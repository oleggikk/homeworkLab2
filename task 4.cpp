#include <stack>
#include <string>
#include <istream>
#include <iostream>

bool openingBracket(char left)
{
    return ('(' == left || '{' == left || '[' == left);
}

bool closingBracket(char left, char right)
{
    return (('(' == left && ')' == right) || ('[' == left && ']' == right) || ('{' == left && '}' == right));
}

void task4()
{
    std::string input;
    getline(std::cin >> std::ws, input);
    std::stack<char> stack_of_brackets;
    std::string::const_iterator it;

    char bracket;

    for (it = input.begin(); it != input.end(); ++it)
    {
        bracket = *it;
        if (openingBracket(bracket))
        {
            stack_of_brackets.push(bracket);
        }
        else if (closingBracket(stack_of_brackets.top(), bracket))
        {
            stack_of_brackets.pop();
        }
        else
        {
            stack_of_brackets.push(bracket);
            break;
        }
    }

    if (stack_of_brackets.empty())
    {
        std::cout<<"yes";
    }
    else
    {
        std::cout<<"no";
    }

}