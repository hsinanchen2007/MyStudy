### 解题思路
设置一个进位，完全按照ALU实现来的

### 代码

```c
char * addBinary(char * a, char * b){
    //较笨的思路，先把a,b都变为十进制数，再相加，之后变为二进制数，存在一个字符型数组中
    char *res;
    char *now;
    int acc=0;
    int i,j;
    int k;
    int len;
    int len1,len2;
    len1=strlen(a);
    len2=strlen(b);
    len=len1>len2?len1:len2;
    now=(char *)malloc(sizeof(char)*(len+2));
    k=len;
    for(i=len1-1,j=len2-1;i>=0&&j>=0;i--,j--){
        if(a[i]-'0'+b[j]-'0'+acc==3){
            now[k--]='1';
            acc=1;
        }
        else if(a[i]-'0'+b[j]-'0'+acc==2){
            now[k--]='0';
            acc=1;
        }
        else if(a[i]-'0'+b[j]-'0'+acc==1){
            now[k--]='1';
            acc=0;
        }
        else{
            now[k--]='0';
            acc=0;
        }
    }
    while(i>=0){
        if(a[i]-'0'+acc==2){
            now[k--]='0';
            acc=1;
        }
        else if(a[i]-'0'+acc==1){
            now[k--]='1';
            acc=0;
        }
        else{
            now[k--]='0';
            acc=0;
        }
        i--;
    }
    while(j>=0){
        if(b[j]-'0'+acc==2){
            now[k--]='0';
            acc=1;
        }
        else if(b[j]-'0'+acc==1){
            now[k--]='1';
            acc=0;
        }
        else{
            now[k--]='0';
            acc=0;
        }
        j--;
    }
    if(acc==1){
        now[0]='1';
        now[len+1]='\0';
        return now;
    }
    res=(char *)malloc(sizeof(char)*(len+1));
    for(i=0,j=1;i<len;i++,j++){
        res[i]=now[j];
    }
    res[len]='\0';
    return res;

}
```