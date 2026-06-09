### 解题思路
分类讨论，注意特殊情况

### 代码

```c
bool detectCapitalUse(char * word){
    if(word==""||word[1]=='\0')return true;
    
    int A=*word<'a'?1:0;
    if(A)
        for(int i=1;word[i+1]!='\0';++i)
            if((word[i]<'a'&&word[i+1]>='a')||(word[i]>='a'&&word[i+1]<'a'))
                return false;
    if(!A)
        for(int i=0;word[i]!='\0';++i)
            if(word[i]<'a')
                return false;
    return true;
}
```