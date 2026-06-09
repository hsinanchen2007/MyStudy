## string版
```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for (auto ch : S) {
            if (res.empty() || ch != res.back())
                res.push_back(ch);
            else
                res.pop_back();
        }
        return res;
    }
};
```
### 复杂度分析
- 时间复杂度：*O(N)*，其中 *N* 是字符串的长度
- 空间复杂度：*O(N)*

## cnt版
```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        int cnt = 0;
        for (auto ch : S) {
            if (cnt == 0 || ch != S[cnt - 1])
                S[cnt++] = ch;
            else
                --cnt;
        }
        S.resize(cnt);
        return S;
    }
};
```
### 复杂度分析
- 时间复杂度：*O(N)*，其中 *N* 是字符串的长度
- 空间复杂度：*O(1)*