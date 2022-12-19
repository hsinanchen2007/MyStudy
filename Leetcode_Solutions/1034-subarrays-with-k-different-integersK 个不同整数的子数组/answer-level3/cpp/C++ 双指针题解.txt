### 解题思路
1，双指针，`l`指向左端，`i`作为右端不断往右滑动
2，一旦可以凑出正好`K`个整数，则尝试滑动`l`找到当前情况下的所有可能，并记得复原状态

### 代码

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int N = A.size();
        vector<int> counts(N + 1, 0);
        int l = 0;
        int c = 0;
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (counts[A[i]]++ == 0) ++c;
            while (c > K) {
                if (--counts[A[l]] == 0) --c;
                ++l;
            }
            int t = l;
            if (c == K) {
                // count res
                while (c == K) {
                    if (--counts[A[t]] == 0) --c;
                    ++t;
                    ++res;
                }
                // recover counts
                for (int j = l; j < t; ++j) {
                    if (counts[A[j]]++ == 0) ++c;
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/86f20c20a1bccd597e31fbf8c483814c789b8ae483f291f44eb2ef07736b90c3-image.png)
