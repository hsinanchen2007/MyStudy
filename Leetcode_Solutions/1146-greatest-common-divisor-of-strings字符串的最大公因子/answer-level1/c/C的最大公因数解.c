### 解题思路
据题意分析，满足条件的返回字符串长度必定是两个字符串的最大公因数，找出最大公因数，再进行匹配，太菜了写不出kmp算法匹配（手动泪奔）。

### 代码

```c
char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char * re = (char *)malloc(sizeof(char)*1001);
    int flag = 0,max=0,i,j;
    for (i = 0; i < len1; i++){
    re[i] = str1[i];
    }
    int minLen;
    if(len1>len2)
    {minLen=len1;
    }
    else{
    minLen=len2;
    }
    for(i=minLen;i>0;i--)
{
    if((len1%i)==0&&(len2%i)==0){
        max=i;
        break;
    }
}
for(j=0;j<len1;j++)
{
    if(str1[j]!=re[j%max])
    {
        re[0]='\0';
        flag=1;
    }
}
for(j=0;j<len2;j++)
{
    if(str2[j]!=re[j%max])
    {
        re[0]='\0';
        flag=1;
    }
}
if(flag==0)
{
    re[max]='\0';
}

return re;
}
```