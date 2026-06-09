1. 先判断字符串本身是不是回文，是回文直接返回true，不是回文则跳2。
2. 判断删除左指针的字符串是不是回文，判断删除右指针的字符串是不是回文。如果都不是回文则返回false，否则是回文。

程序运行速度还可以，就是内存占的多了一点，因为要复制两个string，贵在思路清晰。

```cpp
bool validPalindrome_v1(string s)
    {
        int left = 0, right = s.length() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        if (s.length() <= 2)
            return true;

        int left = 0, right = s.length() - 1;

        while (left <right)
        {
            if (s[left] != s[right])
            {
                string temp = s;
                s.erase(left, 1);
                string eraseLeft = s;
                temp.erase(right, 1);
                string eraseRight = temp;
                return (validPalindrome_v1(eraseLeft) || validPalindrome_v1(eraseRight));
            }
            ++left;
            --right;
        }
        return true;
    }
```
