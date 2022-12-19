### 解题思路
申请的res数组0号单元先不用，num大于0时返回res+1，否则令res[0]=‘-’并返回res
不过好像挺麻烦的
### 代码

```c
char * convertToBase7(int num){
    if(num==0) return "0";
    char str[33];
    int top=0;
    int cmp=abs(num);
    while(cmp!=0){
        str[++top]=cmp%7+48;    //0号单元暂且不用
        cmp/=7;
    }
    str[top+1]='\0';
    int i=1;
    char *res=(char*)malloc(sizeof(char)*(top+2));
    res[top+1]='\0';
    while(top>=1)res[i++]=str[top--];
    if(num>0) return res+1;
    res[0]='-';
    return res;
}
```