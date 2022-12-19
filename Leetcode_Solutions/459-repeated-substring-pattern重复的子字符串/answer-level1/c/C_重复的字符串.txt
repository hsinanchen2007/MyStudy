### 解题思路
从 1~n/2 依次作为子串长度，为了保证循环，必然有母串长度length%约子串长度i==0
设定子串长度i之后，依次对比母串中的字符s[j]和s[j%i]]

### 代码

```c
bool repeatedSubstringPattern(char * s){
    int length=0;
    for(int i=0;s[i]!='\0';++i)++length;
    
    for(int i=1;i<=length/2;++i)
        if(length%i==0)
        {
            bool flag=true;
            for(int j=0;j<length;++j)
                if(s[j]!=s[j%i])
                {
                    flag=false;
                    break;
                }
            if(flag) return true;           
        }
    return false;
}
```