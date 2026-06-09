### 解题思路
双指针。分别指向字符串的首尾元素，前指针从前往后查找元音字母，后指针从后往前查找元音字母。

两层循环，第一层即从前往后找元音字母，找到就进入二层循环，从后往前查找元音字母，找到后互换前后两个元音字母，j减1并跳出二层循环，继续遍历一层循环，直到i不再小于j即找完了字符串的所有元音字母。

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            if (isVowel(s[i])) {
                while (j > i) {
                    if (isVowel(s[j])) {
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                        j--;
                        break;
                    }
                    j--;
                }
            }
            i++;
        }
        return s;
    }
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};
```