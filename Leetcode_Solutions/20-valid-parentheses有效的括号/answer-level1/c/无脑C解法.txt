//无脑C解法

bool isValid(char * s){
    int len = strlen(s);
    char *help = (char *)malloc(sizeof(char)*len);
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    int top = -1;

    if(len % 2 != 0)
    {
        return false;
    }
    else
    {
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                a1++;
            }
            else if(s[i] == ')')
            {
                a2++;
            }
            else if(s[i] == '[')
            {
                b1++;
            }
            else if(s[i] == ']')
            {
                b2++;
            }
            else if(s[i] == '{')
            {
                c1++;
            }
            else if(s[i] == '}')
            {
                c2++;
            }
        }
        if(a1 == a2 && b1 == b2 && c1 == c2)
        {
            //检验顺序
            for(int i = 0; i < len; i++)
            {
                if(i == 0)
                {
                    help[++top] = s[i];
                }
                else
                {
                    if(s[i] == ')' && help[top] == '(')
                    {
                        top--;
                    }
                    else if(s[i] == ']' && help[top] == '[')
                    {
                        top--;
                    }
                    else if(s[i] == '}' && help[top] == '{')
                    {
                        top--;
                    }
                    else
                    {
                        help[++top] = s[i];
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }

    return top == -1 ? true : false;
}