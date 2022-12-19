```c
char * convertToBase7(int num){
    if(num==0) return "0";
    int i,digit=0,flag=num>0?0:1;
    int copy=num>0?num:-1*num;
    num=copy;
    while(num!=0){
        digit++;
        num=num/7;
    }
    char s[digit+flag+1];
    for(i=digit+flag-1;i>=flag;i--){
        s[i]=copy%7+48;
        copy=copy/7;
    }
    if (flag) s[0]='-';
    s[digit+flag]=0;
    char* str;
    str=s;
    return str;
}
```