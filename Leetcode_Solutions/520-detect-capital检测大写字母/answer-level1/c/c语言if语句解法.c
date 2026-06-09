### 解题思路
各种判断，很笨。
### 代码

```c
bool detectCapitalUse(char * word){
    if(word[0]>=65&&word[0]<=90)
    {
        if(word[1]>=65&&word[1]<=90)
        {
            for(int i=2;i<strlen(word);i++)
            {
                if(word[i]>=97&&word[i]<=122)
                return false;
            }
            return true;
        }
        else
        {
            for(int i=2;i<strlen(word);i++)
            {
                if(word[i]>=65&&word[i]<=90)
                return false;
            }
            return true;
        }
    }
    else
    {
        for(int i=1;i<strlen(word);i++)
        {
            if(word[i]>=65&&word[i]<=90)
            return false;
        }
        return true;
    }
}
```