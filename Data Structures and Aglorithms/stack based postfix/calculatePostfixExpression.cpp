#include <string>
#include <stack>
#include <iostream>
using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    int value = 0; // calculated value
    if(length == 0) // if string is empty
        return 0;
    stack<int> stack; // create a stack
    
    for (int i = 0; i < length; i++) // run through the lenght of the array
    {
        if(expression[i] != "+" && expression[i] != "-" && expression[i] != "*" && expression[i] != "/" && expression[i] != "%") // checks if it is a number
        {
            int num = stoi(expression[i]); // converts string to int and adds to stack
            stack.push(num);
            
        }
        else{
            int a = 0;
            int b = 0;

            if (stack.size() >= 1){ // is stack is large enough take the top to values to uses for
                a = stack.top();
                stack.pop();
            }
            if(stack.size() > 0)
            {
                b = stack.top();
                stack.pop();
            }
            else // stack is empty
            {
               return 0;
            }
            
            if(expression[i] == "+") // adds top two ints and sets it to value
                 value = b + a;
            if(expression[i] == "-")// subtracts top two ints and sets it to value
                value = b - a;
            if(expression[i] == "*")// multiplies top two ints and sets it to value
                value = b * a;
            if(expression[i] == "/")// divides top two ints and sets it to value
                value = b / a;
            if(expression[i] == "%")// gets the remainder top two ints and sets it to value
                value = b % a;
            
            stack.push(value); // pushes value back to the top of the stack
          
        }
    }
    if(stack.size() == 1) // final value should be the only int left in stack
        return stack.top();
    else
        return 0; // if untrue return 0
}

//
//int main()
//{
//    string exp1[] = {"+"};
//    string exp2[] = {"-"};
//    string exp3[] = {"*"};
//    string exp4[] = {"/"};
//    string exp5[] = {"%"};
//    string exp1a[] = {"1", "+"};
//    string exp2a[] = {"1", "-"};
//    string exp3a[] = {"1", "*"};
//    string exp4a[] = {"1", "/"};
//    string exp5a[] = {"1", "%"};
//
//    //ASSERT_EQ(calculatePostfixExpression(exp1,1), 0);
//    if (calculatePostfixExpression(exp1,1) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp1,1) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp2,1), 0);
//    if (calculatePostfixExpression(exp2,1) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp2,1) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp3,1), 0);
//    if (calculatePostfixExpression(exp3,1) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp3,1) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp4,1), 0);
//    if (calculatePostfixExpression(exp4,1) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp4,1) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp5,1), 0);
//    if (calculatePostfixExpression(exp5,1) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp5,1) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp1a,2), 0);
//    if (calculatePostfixExpression(exp1a,2) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp1a,2) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp2a,2), 0);
//    if (calculatePostfixExpression(exp2a,2) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp2a,2) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp3a,2), 0);
//    if (calculatePostfixExpression(exp3a,2) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp3a,2) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp4a,2), 0);
//    if (calculatePostfixExpression(exp4a,2) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp4a,2) << ".\n";
//        return 1;
//    }
//    //ASSERT_EQ(calculatePostfixExpression(exp5a,2), 0);
//    if (calculatePostfixExpression(exp5a,2) != 0)
//    {
//        cout << "expected/correct value 0, actual value when testing " << calculatePostfixExpression(exp5a,2) << ".\n";
//        return 1;
//    }
//    return 0;
//}
//
//
