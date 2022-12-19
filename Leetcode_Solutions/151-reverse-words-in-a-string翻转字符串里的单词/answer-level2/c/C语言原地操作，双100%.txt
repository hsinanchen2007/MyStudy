### 解题思路
先整体翻转。
然后找出单词进行部分翻转。
最后去除多余的空格。
注意把\0的位置提前。
还有就是注意异或交换的时候一定要确保两个指针指向的不是同一个内存空间。

### 代码

```c
char * reverseWords(char * s){
    int length=strlen(s);
    if(length==0){
        return s;
    }
    // Reverse total string
    for(int i=0,j=length-1;i<j;i++,j--){
        s[i]^=s[j];
        s[j]^=s[i];
        s[i]^=s[j];
    }
    // Reverse word
    int pos=0;
    for(int i=0;i<=length;i++){
        if(s[i]==' ' ||s[i]=='\0'){
            for(int wa=pos,wb=i-1;wa<wb;wa++,wb--){
                s[wa]^=s[wb];
                s[wb]^=s[wa];
                s[wa]^=s[wb];
            }
            pos=i+1;
        }
    }
    // Remove extra space
    pos=0;
    int flag=0;
    for(int i=0;i<=length;i++){
        if(s[i]!=' ' && s[i]!='\0'){
            s[pos++]=s[i];
            flag=1;
        }
        else if(flag){
            s[pos++]=s[i];
            flag=0;
        }
    }
    // Change the end position
    pos=pos-1>=0?pos-1:0;
    s[pos]='\0';
    return s;
}
```