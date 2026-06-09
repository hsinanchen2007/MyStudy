### 解题思路
千万注意是除7取余。。。。。

### 代码

```c
#include <string.h>
void reverse(char*s,int low,int high){
    while(low<high){
        char t=s[low];
        s[low]=s[high];
        s[high]=t;
        low++;high--;
    }
}
char * convertToBase7(int num){
    if(num==0){
        char*res=(char*)malloc(2*sizeof(char));
        res[0]='0';
        res[1]=0;
        return res;
    }
    int flag=(num>=0)?0:1;
    num=num>=0?num:-num;
    int temp=num,sum=0,i=0;
    while(temp>0){
        sum++;
        temp/=7;
    }
    char*res=(char*)malloc((sum+flag+1)*sizeof(char));
    memset(res,0,sizeof(char)*(sum+flag+1));
    if(flag==1){
        res[i++]='-';
    }
    while(num>0){
        int t=num%7;
        res[i++]='0'+t;
        num/=7;
    }
    reverse(res,flag,i-1);
    return res;
}
```