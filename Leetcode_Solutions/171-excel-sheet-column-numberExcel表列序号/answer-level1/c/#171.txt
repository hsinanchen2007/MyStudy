### 解题思路
回忆了一下pow函数，求幂
### 代码

```c
int titleToNumber(char * s){
    if(s==NULL) return 0;
int s_length=strlen(s),result=0,i=s_length-1,j=0;
while(i>=0){
    result+=pow(26,j)*(s[i]-'A'+1);
    i--;j++;
}
return result;
}
```