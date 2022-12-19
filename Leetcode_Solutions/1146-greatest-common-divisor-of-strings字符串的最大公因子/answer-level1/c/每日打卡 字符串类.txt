### 解题思路
反复找相同的部分  参考别人的方法

### 代码

```c
char * gcdOfStrings(char * str1, char * str2)
{
    if(strstr(str1,str2)==NULL&&strstr(str2,str1)==NULL) return "";
    int pt_a=0,pt_b=0,cmp=0;                //指针移位记录
    do
    {
        cmp=strcmp(str1+pt_a,str2+pt_b);
        cmp>0?(pt_a+=strlen(str2+pt_b)):(pt_b+=strlen(str1+pt_a));  
        if(strstr(str1+pt_a,str2+pt_b)==NULL&&strstr(str2+pt_b,str1+pt_a)==NULL) return "";
    }while(cmp);
    return str1+pt_a;
}
```