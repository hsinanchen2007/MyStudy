思路 用三个指针a, b, c从左到右遍历字符串分别记录‘a'，’b'，‘c'的位置，每次更新下标最小的字母，且每次更新后结果数增加。

```c++ []
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, a, b, c;
        a = b = c = -1;
        while (max(a, max(b, c)) < int(s.size())){
            if (a <= b && a <= c){
                a++;
                while (a < s.size() && s[a] != 'a') a++;
            } else if (b <= a && b <= c){
                b++;
                while (b < s.size() && s[b] != 'b') b++;
            } else if (c <= b && c <= a){
                c++;
                while (c < s.size() && s[c] != 'c') c++;
            }
            if (max(a, max(b, c)) >= int (s.size())) break;
            if (min(a, min(b,c)) != -1) res += s.size() - max(a, max(b, c));
        }
        return res;
    }
};
```
