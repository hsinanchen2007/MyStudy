click here

```
typedef enum
{
    NONE = 0,
    FOUND_OP = 1,
    FOUND_NUM = 2,
    END
}STATE;

int myAtoi(char * str){

    STATE state = NONE;

    char *cur = str;

    int op;
    long long num = 0;

    while(*cur)
    {
        char c = *cur;
        cur++;

        if(state == NONE)
        {
            if(c == ' ') continue;  // ignore blank charactor
            else if(c == '-') 
            {
                op = -1;
                state = FOUND_OP;
            }
            else if(c == '+')
            {
                op = 1;
                state = FOUND_OP;
            }
            else if( (c <= '9') && (c >= '0') )
            {
                op = 1;
                num = c - '0';
                state = FOUND_NUM;
            }
            else
            {
                state = END;
            }
        }
        else if( (state == FOUND_OP) || (state == FOUND_NUM) )
        {
            if( (c <= '9') && (c >= '0') )
            {
                num = ( (long long)abs(num) * 10 + (c - '0') ) * op;

                // whether overflow
                if(num != (int)num)
                {
                    num = op == 1 ? INT_MAX : INT_MIN;
                    state = END;
                }
            }
            else
            {
                state = END;
            }
        }
        else
        {
            assert(state == END);
            break;
        }
    }

    return (int)num;
}
```
