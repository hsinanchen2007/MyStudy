# 思路
以一个单词为单位反转，构造i，j，表示反转单词的起点与终点，根据字符是否为空格，或是否到达字符串尾部，调用构造的反转函数。
# 代码
```
class Solution {
public:
    void reverse(string& s, int i, int j) {
        while(i < j)
            swap(s[i++], s[j--]);
    }
    
    string reverseWords(string s) {
        int i = 0, j = 0, len = s.length();
        while(j < len) {
            if(s[j] == ' ') { // 一个单词结束
                reverse(s, i, j-1);
                i = j+1;
            }
            if(j == len-1) // 到达字符串尾部
                reverse(s, i, j);
            j++;
        }
        return s;
    }
};
```
执行用时：12 ms
