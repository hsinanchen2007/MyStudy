话不多说，先上图
![rst-doublePointer.png](https://pic.leetcode-cn.com/aea0b6c4237393f713c7f10d35ada5d723ced6ad6d597d316789c0270d6f2623-rst-doublePointer.png)

**思路**：
1. 先将字符串中的大写字母全部转换为小写字母；
2. 设置头尾双指针，两个指针分别从字符串头部和尾部开始遍历字符串；
    - 若当前指针所指元素不是字母或者数字，则该指针后移（头指针）或者前移（尾指针）
    - 如果当前两个指针所指元素相等，则头指针后移并且尾指针前移；如果不相等，则直接退出循环并返回false
    - 当头指针大于尾指针时退出循环

**代码如下**：
```
void alphToLower(char* s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if ('A' <= s[i] <= 'Z')
            s[i] = tolower(s[i]);
    }
}

bool isPalindrome(char* s) {
    int len = strlen(s);
    // set a front pointer which point at the beginning of the string
    char* pf = s;
    // set a tail pointer
    char* pt = s + len - 1;
    bool ret = true;
    alphToLower(s);
    puts(s);
    while (pf < pt)
    {
        if (('a' <= *pf && *pf <= 'z') || ('0' <= *pf && *pf <= '9'))
        {
            if (('a' <= *pt && *pt <= 'z') || ('0' <= *pt && *pt <= '9'))
            {
                if (*pf == *pt)
                {
                    pf++;
                    pt--;
                    continue;
                }
                else
                {
                    ret = false;
                    break;
                }
            }
            else
            {
                pt--;
                continue;
            }
        }
        else
            pf++;
    }
    return ret;
}
```

**复杂度分析**：
- 时间复杂度：$O(N)$。因为只遍历字符串一次。
- 空间复杂度：$O(1)$。没有额外空间申请。