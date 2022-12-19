```
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 1; i < S.size(); ++i) {
            string t = S.substr(i) + S.substr(0, i);
            if (t < res) res = t;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/06b30546489efd56e99a8535cd1cbcbb200120b48f438304ca9ee52c0640387f-image.png)

