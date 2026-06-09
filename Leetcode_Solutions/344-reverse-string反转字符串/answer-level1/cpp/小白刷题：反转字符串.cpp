遍历字符串长度一半，与对称位置利用和差互换

代码：
```
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            int a = (int)s[i] + (int)s[len -1 - i];
            s[len - 1 - i] = (char)(a - (int)s[len -1 - i]);
            s[i] = (char)(a - (int)s[len - 1 - i]);
        }
    }
};
```
