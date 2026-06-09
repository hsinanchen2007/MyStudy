### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str)
{
    char *p = NULL;
    char *string = NULL;
    int a = 0;
    int b = 0;
    int status = 0;
    int flag = 0;
    long  lastnum =0;
    p = (char*)malloc(5000);
    string = (char*)malloc(5000);
    memset(p,0x00,5000);
    memset(string,0x00,5000);
    p = str;
    a = strlen(p);
    for(int i = 0;i<a;i++)
    {
        if(p[i] == '+' || p[i] == '-' || (p[i]>=  '0' && p[i] <= '9' ) )
        {
            if(status == 1)
            {
                if(p[i] == '+' || p[i] == '-')
                    break;
            }
            status = 1; 
            if( flag == 0)
            {
                sprintf(string,"%c",p[i]);
                flag = 1;
            }
            else
            {
                sprintf(string,"%s%c",string,p[i]);
            }
            
        }
        else
        {
            if(status ==  0)
            {
                if(p[i] == ' ')
                {
                    
                    continue;
                }
                else
                {
                    
                    break;
                }
            }
            else{
                break;
           }
        }
        
    }

    b = strlen(string);
    
    if(string[0] == '+' )
    {
        if(string[1] >='0'&& string[1] <= '9')
        {
        for ( int i = 1; i <b;i++)
        {
            lastnum = lastnum *10;
            lastnum = (string[i] - 48 ) + lastnum;
        }
        }
    }
    else if (string[0] == '-')
    {
        if(string[1] >='0' && string[1] <= '9')
        {
        for ( int i = 1; i <b;i++)
        {
            lastnum = lastnum *10;
            lastnum = (string[i] - 48 ) + lastnum;
            if(lastnum > INT_MAX)  
            {
                break;
            }
        }
        lastnum = 0 - lastnum;
        }
    }
    else
    {
        for ( int i = 0; i <b;i++)
        {
            lastnum = lastnum *10;
            lastnum = (string[i] - 48 ) + lastnum;
            if(lastnum > INT_MAX) 
            {
                break;
            }
        }
    }
    
    if(lastnum > INT_MAX)  
    {
        lastnum = INT_MAX;
    }
    else if (lastnum < INT_MIN)
    {
        lastnum = INT_MIN;
    }
    
    return lastnum;
}
```