```
int evalRPN(char ** tokens, int tokensSize){
     int *stack = (int *)malloc(sizeof(int)*tokensSize);
     int top = 0;
     for(int i = 0; i < tokensSize; i++)
     {
         int length = strlen(tokens[i]);
         if(tokens[i][0]>='0' && tokens[i][0] <= '9')
         {
             stack[top] = 0;
             for(int j = 0; j < length; j++)
             {
                 stack[top] = stack[top] + (tokens[i][j] - '0')*pow(10,length - 1 - j);
             }
             top++;
         }
         else
         {
             if(tokens[i][1] >='0' && tokens[i][1] <= '9')
             {
                 stack[top] = 0;
                 for(int j = 1; j < length; j++)
                 {
                    stack[top] = stack[top] - (tokens[i][j] - '0')*pow(10,length - 1 - j);
                 }
                 top++;
             }
             else
             {
            int a = stack[top - 2];
            int b = stack[top - 1];
            int result;
            if(tokens[i][0] == '+')
                 result = a + b;
            else if(tokens[i][0] == '-')
                 result = a - b;
            else if(tokens[i][0] == '*')
                 result = a * b;
            else 
                 result = a / b;
            stack[top - 2] = result;
            top = top - 1;
             }
         }
     }
     return stack[0];
}
```
