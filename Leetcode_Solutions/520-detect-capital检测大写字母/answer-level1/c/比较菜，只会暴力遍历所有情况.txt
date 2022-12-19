### 解题思路
1.一个字母，任何情况都满足
2.多个字母
2.1 都是大写
2.1.1第二个字母大写
2.2 都是小写
2.2.1第二个字母小写
2.3 首字母大写其余小写
2.3.1第二个字母小写
2里面走哪条分支需要根据下一个字母。



### 代码

```c
bool detectCapitalUse(char * word){
    #define ISUPPER(c) (((c>='A')&&(c<='Z')) ? 1:0)
    #define ISLOWER(c) (((c>='a')&&(c<='z')) ? 1:0)
    #define True 1
    #define False 0
    int len = strlen(word);
    int i;
    if(len == 1) return True;
    if(ISLOWER(*word))
    {
        for(i=1;i<len;i++)
        {
            if(ISLOWER(*(word+i))) continue;
            else return False;
        }
        return True;
    }
    if(ISUPPER(*word))
    {
        if(ISUPPER(*(word+1)))
        {
            for(i=2;i<len;i++)
            {
                if(ISUPPER(*(word+i))) continue;
                else return False;
            }
            return True;
        }
        if(ISLOWER(*(word+1)))
        {
            for(i=2;i<len;i++)
            {
                if(ISLOWER(*(word+i))) continue;
                else return False;
            }
            return True;
        }
    }
    return True;

}
```