### 解题思路
此处撰写解题思路

### 代码

```c
char * gcdOfStrings(char * str1, char * str2){
    int i = 0,j=0,k=0,l;
    char * t;
    //*t = 'A';
    int flag=-1,flag1=0,flag2=0;
    while(*(str1+j)!='\0')
    {
        j++;
    }
    while(*(str2+k)!='\0')
    {
        k++;
    }
    for(;*(str1+i)!='\0'&&*(str2+i)!='\0';i++)
    {
        if(*(str1+i)==*(str2+i))
        {
            //*(t+i)=*(str1+i);
            if(j%(i+1)==0&&k%(i+1)==0)
            {
                
                flag1=1;
                flag2=1;
                for(l=0;l<j;l++)
                {
                    if(*(str1+l%(i+1))==*(str1+l))
                    {
                    }
                    else{
                        
                        flag1=0;
                        break;
                    }
                }
                for(l=0;l<k;l++)
                {
                    if(*(str2+l%(i+1))==*(str2+l))
                    {
                    }
                    else{
                        flag2=0;
                        break;
                    }
                }
                if(flag1&&flag2)
                {
                    flag=i;
                }
            }
        }
        else
        {
            *str1 = '\0';
            return str1;
        }
        
    }
    *(str2+flag+1)='\0';
    return str2;
}
```