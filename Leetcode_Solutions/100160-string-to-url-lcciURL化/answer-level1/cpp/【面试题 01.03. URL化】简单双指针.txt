## 思路：双指针
同 [【剑指Offer】面试题05.替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/solution/mian-shi-ti-05-ti-huan-kong-ge-shuang-zhi-zhen-by-/)

### 代码

```cpp
class Solution {
public:
    string replaceSpaces(string S, int length) {
        if (S.empty()) return S;
        int cnt = 0;
        for (int i = 0; i < length; ++i) {
            if (S[i] == ' ') ++cnt;
        }
        int newLen = length + cnt * 2, j = newLen - 1;
        for (int i = length - 1; i >= 0 && i != j; --i) {
            if (S[i] == ' ') {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
            } else {
                S[j--] = S[i];
            }
        }
        S[newLen] = '\0';
        return S;
    }
};
```