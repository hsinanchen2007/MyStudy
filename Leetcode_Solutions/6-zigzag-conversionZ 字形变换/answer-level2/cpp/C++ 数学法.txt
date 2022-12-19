### 解题思路
利用模运算确定字符所在的行，逐次遍历

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> S(numRows);
        int K = (numRows - 1) << 1;
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            int j = numRows - 1 - abs((i % K) - (numRows - 1));
            S[j] += s[i];
        }
        string res;
        for (auto& w : S) {
            res += w;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/e33a9d2bd9b9b595b1c036d85290d1c5d908742a5c1a9b9b4547b90c5f056e07-image.png)
