双指针，一头一尾，若对应辅音字母则向中间移动，两个均为元音字母则交换并向中间移动，直到两指针相遇

代码：
```
class Solution {
public:
    string reverseVowels(string s) {
        string letter = "AEIOUaeiou";
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (letter.find(s[i]) == letter.npos)
                i++;
            else if (letter.find(s[j]) == letter.npos)
                j--;
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
```
