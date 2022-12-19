```
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int l = 0;
        int r = N;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (citations[N - m] >= m) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};
```

![image.png](https://pic.leetcode-cn.com/af6865043e5a702f67de727569fc9ac9beb769d74e7b251c30091cf2c82e047d-image.png)

