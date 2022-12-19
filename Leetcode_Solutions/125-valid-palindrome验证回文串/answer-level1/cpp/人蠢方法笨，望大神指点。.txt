### 解题思路
首先将字符串中的大写字母都改成小写，然后从字符串的两边开始比较，比较的时候直接跳过非字母数字的部分就可以了。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);    
        int a = 0, t = s.size() - 1;
        while(a < t)
        {
            while(isalpha(s[a]) == 0 && isdigit(s[a]) == 0)
            {
                a++;
                if(a == s.size())
                {
                    return true;//空字符定义为有效字符，其实就是一个边界检测
                }
            }
            while(isalpha(s[t]) == 0 && isdigit(s[t]) == 0)
            {
                t--;
            }
            if(s[a] != s[t])
            {
                return false;
            }
            a++;
            t--;
        }
        return true;
    }
};
```