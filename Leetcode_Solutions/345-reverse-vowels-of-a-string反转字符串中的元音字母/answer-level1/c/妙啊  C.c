### 解题思路
先抽取 元音字符存入一个s字符串数组中，然后再逆序填入原来数组中
巧妙的地方：将抽取的地方 进行标记处理

### 代码

```c
char * reverseVowels(char * s){
    int len=strlen(s);
    if(len<=1)          return s;
    char vowel[len+1];
    int j=0;
    for(int i=0;i<len;i++)
    {
        if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || 
            tolower(s[i]) == 'o' || tolower(s[i]) == 'u')
            {
                vowel[j++]=s[i];
                s[i]='*';
            }
    }
    vowel[j]='\0';
    for(int i=0;i<len;i++)
    {
        if(s[i]=='*')
            s[i]=vowel[--j];
    }
    return s;

}
