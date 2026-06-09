```
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.size() + 1;
        vector<int> res(N, 0);
        for (int i = 1; i < N; ++i) {
            res[i] = i;
            int t = i;
            while (--t >= 0 && S[t] == 'D') {
                swap(res[t], res[t + 1]);
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/f5b85960f9c7636f65acd07ea18b95b496442a8b500ac0b32ae8ea0653b8be69-image.png)
