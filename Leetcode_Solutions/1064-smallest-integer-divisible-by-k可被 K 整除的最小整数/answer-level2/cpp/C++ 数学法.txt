```
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        vector<bool> seen(K, false);
        int n = 0;
        int c = 0;
        while (!seen[n]) {
            seen[n] = true;
            n = (10 * n + 1) % K;
            ++c;
        }
        return (n == 0) ? c : -1;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c98eaab83438cc372921c23489f9393609b2e5c6b6f077c99055398998b037fa-image.png)
