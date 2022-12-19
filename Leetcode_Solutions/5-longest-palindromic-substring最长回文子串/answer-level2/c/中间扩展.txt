根据回文的定义从中间向两边去寻找，不满足回文条件时推出循环，此时得到的长度就是当前以i为中心的回文的长度。
```c
/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-27 23:36:09
 * @LastEditTime: 2019-09-27 23:36:09
 * @LastEditors: your name
 */
/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

#define max(x, y) ((x) > (y) ? (x) : (y))
int getPalindromLengthWithCenter(char *s, int length, int i)
{
    int length1;
    int length2;
    int left = i;
    int right = i;
    while (left >= 0 && right < length && s[left] == s[right])
    {
        left--;
        right++;
    }
    length1 = right - left - 1;
    left = i;
    right = i + 1;
    while (left >= 0 && right < length && s[left] == s[right])
    {
        left--;
        right++;
    }
    length2 = right - left - 1;
    return max(length1, length2);
}
char *longestPalindrome(char *s)
{
    char *temp = NULL;
    int length = strlen(s);
    int maxlen = 0;
    int maxPos = 0;
    int tempLen = 0;
    for (int i = 0; i < length; i++)
    {
        tempLen = getPalindromLengthWithCenter(s, length, i);
        if (tempLen > maxlen)
        {
            maxlen = tempLen;
            maxPos = i;
        }
    }
    temp = (char *)malloc(sizeof(char) * (maxlen + 1));
    memcpy(temp, &s[maxPos - (maxlen - 1) / 2], maxlen);
    temp[maxlen] = '\0';
    return temp;
}

```