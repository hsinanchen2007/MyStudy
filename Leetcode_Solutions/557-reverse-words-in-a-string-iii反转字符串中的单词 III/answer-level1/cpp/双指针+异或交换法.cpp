以[反转字符串](https://leetcode-cn.com/problems/reverse-string/)这题作为基础。

这里要注意的就是，这是一个“双指针法”，在运行的过程中会有一个头指针固定，尾指针不断向前移动，遇到空格即为头指针和尾指针之间为一个单词，对这个单词进行反转即可。
而使用的交换算法是反转字符串中最快速的异或交换法，实际上还是一个双指针法。

```c++
class Solution {
public:
    // 反转字符串
    void reverseString(int front, int tail, string& str) {
        while (front < tail) {
            str[front] ^= str[tail];
            str[tail] ^= str[front];
            str[front++] ^= str[tail--];
        }
    }
    // 确定单词边界
    string reverseWords(string s) {
        int front = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverseString(front, i - 1, s);
                front = i + 1;
            }
        }
        reverseString(front, s.length() - 1, s);
        return s;
    }
};
```

> 执行用时 : 16 ms, 在所有 C++ 提交中击败了98.24%的用户
> 内存消耗 : 11.6 MB, 在所有 C++ 提交中击败了95.48%的用户