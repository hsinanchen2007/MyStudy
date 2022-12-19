### 解题思路
填坑之路

### 代码

```c
int myAtoi(char * str){
    long  a=0;
    int k=1,j=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' '&&j==0)
        { 
            continue;
        }
        if((str[i]=='+'||str[i]=='-')&&(str[i+1]<48||str[i+1]>57))
            break;
        if(str[i]=='+'&&j==0)
            continue;
        if(j==1&&(str[i]=='+'||str[i]=='-'))
            break;
        if((str[i]<48||str[i]>57)&&str[i]!='-')
        {  
            break;
        }
        if(str[i]=='-'&&j==0)
            k=-1*k;
        if(str[i]!='-')
        {
            j=1;
            a=a*10+(int)(str[i]-48);
        }
        if(a*k>INT_MAX)
        return INT_MAX;
        if(a*k<INT_MIN)
        return INT_MIN;
    }
    return a*k;
}
```