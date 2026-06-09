### 思路：双指针
暴力方法，从前向后遍历，遇到空格就替换，则每次替换需要移动空格后面O(n)个字符，所以总时间复杂度为O(n^2)。
我们可以先计算出空格数，然后可得替换后新串总长度，设两个指针i和j分别指向原来字符串末尾和新串末尾，向前移动指针，如果遇到空格就替换，否则将原来字符移到新的位置。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    string replaceSpace(string s) {        
        if (s.empty()) return s;
        int cnt = 0;
        for (char c : s) {
            if (c == ' ') ++cnt;
        }        
        int oldLen = s.size(), newLen = cnt * 2 + oldLen, j = newLen - 1;
        s.resize(newLen);               
        for (int i = oldLen - 1; i >= 0 && j != i; --i) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';                
            } else {
                s[j--] = s[i];                
            }
        }        
        return s;
    }
};
```