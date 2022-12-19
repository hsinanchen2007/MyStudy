### 解题思路
从哈希表里得来的灵感，按照ASCII建立数组，有字符则字符ASCII对应的数组位置就增加1，有超过1的就失败，遍历所有字符都没有超过1的就成功。

### 代码

```c
bool isUnique(char* astr){
    bool isUnique;
    int length = strlen(astr);
    int flo[128] = {0};
    for(int i = 0;i < length;++i)
    {
        flo[astr[i]]++;
        if(flo[astr[i]] > 1)
        {
            isUnique = false;
            break;
        }
        if(i == length - 1)
        {
            isUnique = true;
        }
    }
    // for(int i = 0;i < 128;++i)
    // {
    //     if(flo[i] > 1)
    //     {
    //         isUnique = false;
    //         break;
    //     }
    //     if(i == 127)
    //     {
    //         isUnique = true;
    //     }
    // }
    return isUnique;
}
```