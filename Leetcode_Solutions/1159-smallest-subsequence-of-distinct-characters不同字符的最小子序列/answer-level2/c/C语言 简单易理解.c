![image.png](https://pic.leetcode-cn.com/44c468b8ce9e8caaeb231e0c119351e3f3ebeadf26bcd9d9627c45cafe90cf97-image.png)

```

char res[27];
char *smallestSubsequence(char *text)
{
    int flag[26];
    int index = 0;
    for (size_t i = 0; i < 26; i++)
    {
        flag[i] = 0;
    }

    while (*text != '\0')
    {
        int ch = *text - 'a';
        if (flag[ch] == 1)
        {
            *text++;
            continue;
        }
        while (index != 0 && *text < res[index - 1] && strchr(text, res[index - 1]) != NULL)
        {
            flag[res[index - 1] - 'a']--;
            index--;
        }

        flag[ch]++;
        res[index++] = *text++;
    }
    res[index] = '\0';
    return res;
}

```
