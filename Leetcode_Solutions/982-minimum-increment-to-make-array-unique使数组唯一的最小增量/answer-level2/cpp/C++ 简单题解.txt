思路简单，详见注释
```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int dup = 0; // 重复数个数
        int dup_sum = 0; // 重复数下标和
        int sit_sum = 0; // 空位下标和
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) {
                ++dup;
                dup_sum += A[i];
            } else {
                int t = A[i - 1] + 1;
                // 有空位且还有未放置的重复数，则逐一放置
                while (t < A[i] && dup > 0) {
                    sit_sum += t;
                    --dup;
                    ++t;
                } 
            }
        }
        if (dup > 0) {
            int t = A.back() + 1;
            sit_sum += (2 * t + dup - 1) * dup / 2;
        }
        return sit_sum - dup_sum;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a2298877a8a296531833d8a95b1cff1801c56020cdb73a614641e98deaa011e6-image.png)
