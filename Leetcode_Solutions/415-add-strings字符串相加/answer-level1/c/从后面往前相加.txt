### 解题思路
此处撰写解题思路

### 代码

```c
char * addStrings(char * num1, char * num2){
    int len1=strlen(num1);
    int len2=strlen(num2);
    int len=(len1>len2?len1:len2)+2;
    char* res=(char*)malloc(len);
    int i=len1-1,j=len2-1,k=len-1;
    res[k--]='\0';
    int carry=0;
    while(i>-1&&j>-1){
        int sum=num1[i--]+num2[j--]-'0'-'0'+carry;
        carry=sum/10;
        res[k--]=sum%10+'0';
    }
    while(i>-1){
        int sum=num1[i--]-'0'+carry;
        carry=sum/10;
        res[k--]=sum%10+'0';
    }
    while(j>-1){
        int sum=num2[j--]-'0'+carry;
        carry=sum/10;
        res[k--]=sum%10+'0';
    }
    if(carry){
        res[k--]=carry+'0';
    }
    if(k==-1)
        return res;
    else
        return res+1;
}
```