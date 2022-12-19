### 解题思路
此处撰写解题思路

### 代码

```c
bool canConstruct(char * ransomNote, char * magazine)
{
    char arr[10] = {0};
    int len = strlen(ransomNote);
    int len1 = strlen(magazine);
    if(len > len1)
        return false;
    int cur = 0;
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; j < len1; ++j)
        {
            if(ransomNote[i] == magazine[j])
            {
                magazine[j] = magazine[j] + 32;     //把小写字符改成了大写，避免了在下次查询中又被重复对应的问题
                ++cur;
                break;
            }
        }
    }

    if(cur == len)
        return true;
    return false;

}
```