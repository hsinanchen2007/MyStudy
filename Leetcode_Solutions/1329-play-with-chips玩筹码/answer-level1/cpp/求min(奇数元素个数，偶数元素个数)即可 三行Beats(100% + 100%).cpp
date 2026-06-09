其实就是求 min(奇数元素个数，偶数元素个数)

![image.png](https://pic.leetcode-cn.com/0b129d737e84410b057ca8a231afd23f5c7f1842b052aea7237e3c2db78c515a-image.png)

```
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = 0, N = chips.size();
        for(auto n:chips) if((n&1)==0) even++;
        return min(even, N-even);
    }
};
```

