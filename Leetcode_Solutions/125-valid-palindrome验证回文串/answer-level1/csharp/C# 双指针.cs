执行用时 : 120 ms, 在Valid Palindrome的C#提交中击败了98.09% 的用户
内存消耗 : 21.9 MB, 在Valid Palindrome的C#提交中击败了88.75% 的用户
时间复杂度O(N),空间复杂度O(1)
```
public bool IsPalindrome(string s)
{
    if (s == null)
    {
        return false;
    }
    int point = 0;//指针1 从起点开始
    int point1 = s.Length - 1;//指针2 从终点开始
    while (point < point1)
    {
        //不满足该字符是数字 大写字母 或小写字母 并且没有越界
        while (point < point1 && !((s[point] >= 48 && s[point] <= 57) || (s[point] >= 65 && s[point] <= 90) || (s[point] >= 97 && s[point] <= 122)))
        {
            point++;
        }
        //不满足该字符是数字或者字母
        while (point < point1 && !((s[point1] >= 48 && s[point1] <= 57) || (s[point1] >= 65 && s[point1] <= 90) || (s[point1] >= 97 && s[point1] <= 122)))
        {
            point1--;
        }
        //s[point]或s[point1]是数字
        if ((s[point] >= 48 && s[point] <= 57) || (s[point1] >= 48 && s[point1] <= 57))
        {
            if (s[point] != s[point1])
            {
                return false;
            }
        }
        //两个都不是数字 也就是两个都是字母
        else
        {
            //如果两个字符不相同 并且两个字母忽略大小写仍然不相同
            if (s[point] != s[point1] && (s[point] > s[point1] ? s[point] - s[point1] : s[point1] - s[point]) != 32)
            {
                return false;
            }
        }
        point++;
        point1--;
    }
    return true;
}
```