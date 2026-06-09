先找出解可能的范围，然后使用二分法去猜测是猜大了还是猜小了。题解中的 left 表示如果猜的值太大了，就往左一点，否则往右猜。

所以此题可以看成是 [374. 猜数字大小](https://leetcode-cn.com/problems/guess-number-higher-or-lower/) 的变种，只不过很难想到。

截图记录一下：

![image.png](https://pic.leetcode-cn.com/008a115e85992950bdcb6b7b7511f45098a4ba9c97f9e2b81aceef815c312dc0-image.png)


```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long lo = 0, hi = 0;
        for (auto e : nums) {
            lo = max(lo, (long)e);
            hi += e;
        }
        
        if (nums.size() == 1) return hi;
        if (nums.size() == m) return lo;
        
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (left(nums, mid, m)) { // 是否需要向左猜测
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    bool left(vector<int>& nums, int target, int m) {
        int count = 1, total = 0;
        for (auto e : nums) {
            total += e;
            if (total > target) {
                ++count;
                if (count > m) {
                    return false;
                }
                total = e;
            }
        }
        return true;
    }
};
```
