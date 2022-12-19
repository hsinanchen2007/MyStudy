先创建一个比较长字符串长一个单位的字符数组，逢二进一，最终根据创建字符串首位元素的情况返回字符串首位元素地址或第二位元素地址。为了代码易读，部分步骤另写函数实现。
```c
int length(char * str){
    int len=0;
    while(str[len]!=0) len++;
    return len;
}
void swap(char**a,char**b,int*len_a,int*len_b){
    char* tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
    int tmp_len;
    tmp_len=*len_a;
    *len_a=*len_b;
    *len_b=tmp_len;
}
char * addBinary(char * a, char * b){
    int len_a=length(a),len_b=length(b),len=len_a>len_b?len_a:len_b,index=len;
    char ans[len+2];
    char* res;
    ans[len+1]=0;
    ans[0]='0';
    if(len_a<len_b) swap(&a,&b,&len_a,&len_b);
    while(len_a) ans[index--]=a[--len_a];
    index=len;
    while(len_b) ans[index--]=ans[index]+b[--len_b]-'0';
    for(index=len;index>0;index--)
        if(ans[index]>'1'){
            ans[index]-=2;
            ans[index-1]++;
        }
    if(ans[0]=='1') return res=&ans[0];
    else return res=&ans[1];
}
```