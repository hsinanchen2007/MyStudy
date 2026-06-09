### 解题思路
```
int myAtoi(char * str){
    long res=0;
    int flag=0;
    char * p = str;
    while(*p!='\0'){
        if(*p==' ') p++;
        else if(*p=='+'){
            flag=1;
            p++;
            break;
        }
        else if(*p=='-'){
            flag=-1;
            p++;
            break;
        }
        else if(*p<='9'&&*p>='0'){
            flag=1;
            break;
        }
        else{
            return 0;
        }
    }
    while(*p!='\0'){
        if(*p<='9'&&*p>='0'){
            res=(int)*p-48+res*10;
            if(res>2147483647) break;
        }
        else break;
        p++;
    }
    if(res>2147483647){
        if(flag==1) return INT_MAX;
        else return INT_MIN;
    }

    return ((int)res)*flag;
}
```


### 代码

```c
int myAtoi(char * str){
    long res=0;
    int flag=0;
    char * p = str;
    while(*p!='\0'){
        if(*p==' ') p++;
        else if(*p=='+'){
            flag=1;
            p++;
            break;
        }
        else if(*p=='-'){
            flag=-1;
            p++;
            break;
        }
        else if(*p<='9'&&*p>='0'){
            flag=1;
            break;
        }
        else{
            return 0;
        }
    }
    while(*p!='\0'){
        if(*p<='9'&&*p>='0'){
            res=(int)*p-48+res*10;
            if(res>2147483647) break;
        }
        else break;
        p++;
    }
    if(res>2147483647){
        if(flag==1) return INT_MAX;
        else return INT_MIN;
    }

    return ((int)res)*flag;
}
```