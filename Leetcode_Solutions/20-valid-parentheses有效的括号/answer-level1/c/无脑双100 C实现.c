```
bool isValid(char * s){
    if (s == NULL || strlen(s) == 0)
    {
        return true;
    }
    if (strlen(s) & 1 == 1 || s[0] == ']' || s[0] == ')' || s[0] == '}')
    {
        return false;
    }
    char stack[strlen(s)];
    int top = -1;
    for (int i=0; i<strlen(s); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[++top] = s[i];
        }
        else if (s[i] == ')')
        {
            if (stack[top] == '(')
            {
                stack[top--] = '\0';
            }
            else
            {
                return false;
            }          
        }
        else if (s[i] == ']')
        {
            if (stack[top] == '[')
            {
                stack[top--] = '\0';
            }
            else
            {
                return false;
            }          
        }
        else if (s[i] == '}')
        {
            if (stack[top] == '{')
            {
                stack[top--] = '\0';
            }
            else
            {
                return false;
            }          
        }
    }
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```
