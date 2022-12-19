### 解题思路
先计算字符串长度
再倒着数

注意：剔除字符串末尾的空格

### 代码

```c
int lengthOfLastWord(char * s){
    char* iter=s;
    int lenght=0;
    while(*iter!='\0')
    {
        ++lenght; 
        ++iter;       
    }

    int sum=0;
    for(int i=lenght-1;i>=0;--i)
    {
        if(s[i]==' '&&sum!=0)
            break;
        else if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
            ++sum;
    }
    return sum;
}
```