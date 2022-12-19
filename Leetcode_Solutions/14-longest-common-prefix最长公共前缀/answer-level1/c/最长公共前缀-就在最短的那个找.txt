### 解题思路
此处撰写解题思路
1. 先找最短的字符串，因为“最长公共”前缀取最短的那个
2. 然后依次遍历最短字符串的每个字符，与其他字符串挨个比较，找到一个不同就说明非公共
3. 有可能存在所有字符串都一样的情况

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0)
    {
        return "";
    }

    if (strsSize == 1)
    {
        return strs[0];
    }

    //先找最短的字符串
    int min_len = pow(2, 31)-1;
    int index = 0;
    for(int i=0;i<strsSize;i++)
    {
        if (strlen(strs[i]) < min_len)
        {
            min_len = strlen(strs[i]);
            index = i;
        }
    }

    if (min_len == 0)
    {
        return "";
    }

    int end_flag = 0;
    char *result_str = (char*)malloc(sizeof(char) * (min_len+1));
    if (result_str == NULL)
    {
        return "";
    }
    memset(result_str, 0, sizeof(char) * (min_len+1));

    //遍历最短字符串的每个字符，与其他字符串挨个比较，找到一个不同就说明非公共
    for (int i=0;i<min_len;i++)
    {
        for (int j=0;j<strsSize;j++)
        {
            if (j == index)
            {
                continue;
            }

            if (strs[index][i] != strs[j][i])
            {
                end_flag = 1;
                break;
            }
        }
        if (end_flag)
        {
            memcpy(result_str, strs[index], i*sizeof(char));
            break;
        }
    }

    if (end_flag)
    {
        return result_str;
    }
    else
    {
        return strs[index];
    }
}
```