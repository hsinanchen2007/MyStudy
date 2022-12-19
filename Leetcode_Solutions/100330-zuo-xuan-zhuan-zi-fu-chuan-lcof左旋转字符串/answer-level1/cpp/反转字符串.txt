### 解题思路
此处撰写解题思路
通过三次反转实现字符串的反转
### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size = s.size();
        reverse(s, 0, n);
        reverse(s, n, size);
        reverse(s, 0, size);
        return s;
    }
    void reverse(string &s, int start, int end) {
        int mid = (start + end) / 2;
        for (int i = start; i < mid; ++i) {
            char temp = s[i];
            int tail = end - i + start - 1;
            s[i] = s[tail];
            s[tail] = temp;
        }
    }
};
```