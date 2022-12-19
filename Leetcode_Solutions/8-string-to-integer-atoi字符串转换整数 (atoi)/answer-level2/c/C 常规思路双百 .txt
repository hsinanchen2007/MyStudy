### 解题思路
情况考虑周全即可

### 代码

```c
int myAtoi(char * str){
    long long int count=0;
    int log=0;
    if(*str=='\0') return 0;
    while(*str==' ') str++;
    if(*str>='a'&&*str<='z') return 0;
    if(*str=='-') {
        log=1;
        str++;
    }else if(*str=='+') str++;
    while(*str>='0'&&*str<='9'){
        count+=*str-'0';
        str++;
        if(*str>='0'&&*str<='9') count*=10;
        if(count>=2147483648&&log) return -2147483648;
        if(count>2147483647&&!log) return 2147483647;
    }
    if(log) count*=-1;
    return count;
}
```