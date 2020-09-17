//Evaluation of postfix expression
#include<stdio.h>
/*1.Add a right paranthesis to the start of p.
    2.Scan the Expression from right to left and repeat step 3&4 untill right paranthesis is encountered.
    3.If an operand is encountered push it to the stack.
    4.If an operator is encountered:
        a. Pop the top two elements of the stack(A,B be the top two eleents).
        b. Perform the operation according to the operator as on A(operator)B.
        c. Push the result on to the stack.
5.Pop the Element from the stack and print the result.*/
//Example: (+ + 2 6 + - 13 2 4) = 23
/*Phase-1
    1. Input String.
    2. All oprerands are single digit.
    3. All oprerators are binary(+,-,*,/).
    4. Identify the operators.
    5. Convert Operands into int.
  Phase-2
    1.Operands can be of two digits.
  Phase 3
    1.Operator may be unary and binary.
*/
typedef enum{plus,minus,times,divide,eos,operand}precedence;

precedence get_token(char *symbol,int *n){
    *symbol=expr[(*n)++];//expr[] is globally declared
    switch (*symbol)
    {
    case '+':return plus;
    case '-':return minus;
    case '*':return times;
    case '/':return divide;
    case '\0':return eos;
    default:return operand;
    }
}
int eval_postfix(){
  /*1. Push a RIGHT paranthesis on to the stack and one right paranthesis to the end of infix exp(q2).
    2. Scan q2 from right TO left and repeat step 3-6 for each eleement of q2 untill it is empty.
    3. If an operand is encountered push it to other stack (p) which stores result.
    4. If an right patanthesis is encountered push it on to the stack.
    5. If an operator is encountered:
      a. Repeatedlly pop from the stack and add to p each operator from the top of the stack which has higher
      precenece than the operator.
      b.Push the scanned operator to the stack.
    6. If a left paranthesis is encountered:
      a.Repeatedlly pop from the stack and add to p each operator from the top of the stack until left paranthesis 
      is encountered,
    7. Exit
  example copy 
  */
    precedence token;
    char symbol;
    int op1,op2;
    int n=0;
    int top=-1;
    token=get_token(&symbol,&n);
    while(token!=eos){
        if(token==operand){
            push(s,symbol-'0');
        }
        else{
            op2=pop(s);
            op1=pop(s);
            switch (token)
            {
            case plus:
                push(s,op1+op2);
                break;
            case minus:
                push(s,op1-op2);
                break;
            case times:
                push(s,op1*op2);
                break;
            case divide:
                push(s,op1/op2);
                break;
            default:
                break;
            }
        }
        token=get(&symbol,&n);

    }
}

