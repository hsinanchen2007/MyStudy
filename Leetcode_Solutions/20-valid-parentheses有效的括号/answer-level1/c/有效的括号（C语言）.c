看了官方题解后自己写了C语言版本，利用数组当堆栈，第一次写题解，大家多多包涵~

bool isValid(char * s){
    //如果是空字符串则返回ture
     if(*s == 0)
         return true;
     int len= strlen(s);
     char stack[len];
     int top = 0;
    //遍历字符串
     for(int i=0; i<len; i++)
     {
    //如果是左括号们，则放入栈中
         if(s[i] == '(' || s[i] == '[' || s[i] == '{')
         {
             stack[top] = s[i];
             top++;
         }
    //如果是右括号，但栈空没有能与之配对的左括号，则返回false
         else if(top == 0)
             return false;
    //如果是右括号，栈不空，则判断是否与栈顶括号是一对
         else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
         {
             if(s[i]== ')'&& stack[top-1]=='(')
             {
                 stack[top-1]=0;
                 top--;
             }
             else if(s[i]== ']'&& stack[top-1]=='[')
             {
                stack[top-1]=0;
                top--;
             }
             else if(s[i]== '}'&& stack[top-1]=='{')
             {
                stack[top-1]=0;
                top--;
             }
             else
             {
                 return false;
             }
         }
     }
    //遍历结束后若栈没有空，则说明左括号多，返回false
     if(stack[0]!=0)
     {return false;}
     else
     {return true;}
}