![image.png](https://pic.leetcode-cn.com/82a6d61399281ebd33972524e8aec88b8297542d3afbda7a92fd183a44fec12b-image.png)

```
class Solution {
private:
    enum {
        self = -2,
        direct = -1,
    };
    // record the nodes
    int S;
    // record the count of nodes
    int count;
    // result
    int total;

    void _computeOneNode(const char dp[9][9], const int &begin, const int &end, const int start) {
        
        S |= 1 << start;
        count++;
        if (count >= begin && count <= end) ++total;
        if (count == end) {
            S &= ~(1 << start);
            count--;
            return;
        }
        
        for (int i = 0; i < 9; ++i) {
            if (S & (1 << i))
                continue;
            if (dp[start][i] == direct)
                _computeOneNode(dp, begin, end, i);
            else if (dp[start][i] > 0 && (S & (1 << dp[start][i])))
                _computeOneNode(dp, begin, end, i);
        }
        S &= ~(1 << start);
        count--;
    }
public:
    int numberOfPatterns(int m, int n) {
        char dp[9][9] = {{self,   direct, 1,      direct, direct, direct, 3,      direct, 4},
                         {direct, self,   direct, direct, direct, direct, direct, 4,      direct},
                         {1,      direct, self,   direct, direct, direct, 4,      direct, 5},
                         {direct, direct, direct, self,   direct, 4,      direct, direct, direct},
                         {direct, direct, direct, direct, self,   direct, direct, direct, direct},
                         {direct, direct, direct, 4,      direct, self,   direct, direct, direct},
                         {3,      direct, 4,      direct, direct, direct, self,   direct, 7},
                         {direct, 4,      direct, direct, direct, direct, direct, self,   direct},
                         {4,      direct, 5,      direct, direct, direct, 7,      direct, self}};
        S = 0;
        count = 0;

        total = 0;
        int rc = 0;
        _computeOneNode(dp, m, n, 0);
        _computeOneNode(dp, m, n, 1);
        rc += total * 4;
        
        total = 0;
        _computeOneNode(dp, m, n, 4);
        rc += total;
        return rc;
    }
};
```
