```
int myAtoi(char * str){
    char *p=str;
    int flag=1;
    while(*p!='\0'){
        if(*p==' '){
            p++;
        }
        else if(*p=='+'){
            p++;
            break;
        }
        else if(*p=='-'){
            p++;
            flag=-1;
            break;
        }
        else if(*p>='0' && *p<='9'){
            break;
        }
        else return 0;
    }
    char *q=p;//p指向正负号后面的数字或直接指向数字
    while(*q!='\0'){
        if(*q>='0' && *q<='9')
            q++;
        else break;
    }
    int len=q-p;//数字位数

    long long int ans=0;
    for(int i=0;i<len;i++)
    {
        ans=ans*10+(*p-'0');
        p++;
        if(ans>INT_MAX){
            if(flag==1)return INT_MAX;
            else return INT_MIN;
        }
    }
    
    if(flag==1)
        return (int)ans;
    else return flag*(int)ans;
}
```
