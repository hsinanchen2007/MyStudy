### 解题思路
这里返回的是一个字符串，最后要加个\0,这点不能忽略

### 代码

```c
char * addStrings(char * num1, char * num2){
    int i,j,k;
    int len,len1,len2;
    int acc=0;
    int temp;
    char *now,*res;
    len1=strlen(num1);
    len2=strlen(num2);
    if(len1==0){
        return num2;
    }
    if(len2==0){
        return num1;
    }
    len=len1>len2?len1:len2;
    now=(char *)malloc(sizeof(char)*(len+2));
    now[len+1]='\0';
    k=len;
    i=len1-1;
    j=len2-1;
    while(i>=0&&j>=0){
        temp=num1[i]-'0'+num2[j]-'0'+acc;
        if(temp<10){
            now[k]=temp+'0';
            acc=0;
        }
        else{
            now[k]=temp%10+'0';
            acc=1;
        }
        k--;
        i--;
        j--;
    }
    if(i>=0){
        while(i>=0){
            temp=num1[i]-'0'+acc;
            if(temp<10){
                now[k]=temp+'0';
                acc=0;
            }
            else{
                now[k]=temp%10+'0';
                acc=1;
            }
            k--;
            i--;
        }
        if(acc==1){
            now[k--]='1';
        }
    }
    if(j>=0){
        while(j>=0){
            temp=num2[j]-'0'+acc;
            if(temp<10){
                now[k]=temp+'0';
                acc=0;
            }
            else{
                now[k]=temp%10+'0';
                acc=1;
            }
            k--;
            j--;
        }
        if(acc==1){
            now[k--]='1';
        }
    }
    if(acc==1){//最高位有进位
        now[0]='1';
        res=(char *)malloc(sizeof(char)*(len+2));
        strcpy(res,now);
        return res;
    }
    res=(char *)malloc(sizeof(char)*(len+1));
    for(i=0,j=1;i<len+1;i++,j++){
        res[i]=now[j];
    }
    return res;
}
```