### 解题思路
感觉思维量没有达到中等的水平，用例恶心了点而已，不过总体还是容易的

### 代码

```c
int myAtoi(char * str){
    int min=-2147483648,max=2147483647;
    long long res=0;
    int flag=1,pos=0;
    while(*str!=0){
        if(*str==' '){
            str++;
        }else{
            break;
        }
    }
    if(*str!='+'&&*str!='-'&&!(*str>='0'&&*str<='9')){
        return 0;
    }
    if(*str=='+'){
        flag=1;
        str++;
    }else if(*str=='-'){
        flag=-1;
        str++;
    }
    while(*str!=0&&*str=='0'){
        *str++;
    }
    while(*str!=' '&&*str>='0'&&*str<='9'){
        res=10*res+(*str-'0');
        *str++;
        pos++;
        if(pos>10){
            if(flag==1){
                return max;
            }else{
                return min;
            }
        }
    }
    res=flag*res;
    if(res<=max&&res>=min){
        return res;
    }
    return res>max?max:min;
    
}   
```