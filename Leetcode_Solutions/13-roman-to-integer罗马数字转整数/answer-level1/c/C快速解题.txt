比较前后两个罗马字符对应的数值大小，后面大的话就将前面数值取反
```
int readroma(char roma){
    switch(roma){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
    return 0;
}

int romanToInt(char * s){
    int num = 0;
    //将每个字符转为整数，然后如果当前位小于下一位，累加对应的负数，最后记得处理边界值
    while(*(s+1) != '\0'){
        if(readroma(*s) < readroma(*(s+1))){
            num -= readroma(*s);
        }else{
            num += readroma(*s);
        }
        s++;
    }
    num += readroma(*s);
    return num;
}
```
