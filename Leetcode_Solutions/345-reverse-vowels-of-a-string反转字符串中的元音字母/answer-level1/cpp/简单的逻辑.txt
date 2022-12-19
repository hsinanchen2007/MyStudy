### 解题思路


### 代码

```cpp
class Solution {
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                //s[i]和s[j]都是元音，交换并继续寻找
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            if (!isVowel(s[i]))
                //s[i]不是元音，继续往后寻找
                ++i;
            if (!isVowel(s[j]))
                //s[j]不是元音，继续向前寻找
                --j;
        }
        return s;
    }
};
```