### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if (S.empty() || K <= 0) {
            return S;
        }
        int second = S.size() - 1, count = K;
        string res;
        while (second >= 0) {
            if (S[second] != '-') {
                if (count > 0) {
                    res.push_back(ToUpper(S[second]));
                    count -= 1;
                    if (count == 0) {
                        count = K;
                        res.push_back('-');
                    }
                }
            }
            second -= 1;
        }
//注意需要从中间向两头开始交换
        if (res.size() % 2 == 0) {
            second = res.size() / 2;
            count = second - 1;
        } else {
            second = res.size() / 2 + 1;
            count = second - 2;
        }
        while (second < res.size()) {
            swap(res[count], res[second]);
            second += 1, count -= 1;
        }
        if (res[0] == '-') {
            return res.substr(1);
        }
        return res;
    }
    
    char ToUpper(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            ch -= 32;
        }
        return ch;
    }
};
```