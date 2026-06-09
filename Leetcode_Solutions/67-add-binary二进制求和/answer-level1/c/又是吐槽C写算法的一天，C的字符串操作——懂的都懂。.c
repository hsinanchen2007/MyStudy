```
char * addBinary(char * a, char * b){
    int lena=strlen(a);
    int lenb=strlen(b);
    int lenth=lena>lenb?lena+2:lenb+2; //考虑进位，位数可能会多一位，就lenth申请长一点。
    char* res=(char*)malloc(lenth*(sizeof(char)));
    memset(res,'\0',lenth);     //memset来初始化为'\0'
    lenth-=2;
    while(lena>0||lenb>0){
        int an=lena>0?a[--lena]-'0':0;        //相当于两个指针指向a，b的尾部；短的那一个直接用0来补充
        int bn=lenb>0?b[--lenb]-'0':0;
        if(an+bn+res[lenth]+'0'=='1') res[lenth--]='1';     //以下都是分类处理过程，其实有更简化的分类；
        else if(an+bn+res[lenth]+'0'=='0') res[lenth--]='0';
        else if(an+bn+res[lenth]+'0'=='2') {res[lenth--]='0';res[lenth]='1'-'0';}
        else {res[lenth--]='1';res[lenth]='1'-'0';}
    }
    res[0]+='0';
    if(res[0]!='1') res++;      //处理完了，看res[0]是否产生进位。没有进位直接将res++；
    return res;
}
```
逻辑爆炸的一天。