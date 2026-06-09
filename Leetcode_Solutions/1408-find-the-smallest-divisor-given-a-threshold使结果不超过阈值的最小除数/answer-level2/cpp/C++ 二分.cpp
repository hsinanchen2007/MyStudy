二分查找
为了找到满足条件的正整数N，先确定N的上下限。

根据题目有：

![image.png](https://pic.leetcode-cn.com/f72e6a535227b535f82f776e9c812113f43ef4f0d4b779651bc619fc231ad9bb-image.png)

所以N的上下限为

![image.png](https://pic.leetcode-cn.com/d9426feb484c245fc07806bb0751b092a6749adb57d627651771975dcd5c75ac-image.png)



```
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // binary search
        int lo = 0, hi = 0;
        for (auto n : nums) {
            lo += n/threshold;
            hi = max(hi, n); //上限
        }
        lo = max(1,lo); // 下限
        while (lo < hi) {
            int mid = lo + ((hi-lo) >> 1);
            int curres = 0;
            for (auto n:nums) {
                curres += divided(n,mid);
            }
            if (curres <= threshold) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }

    int divided (int n, int div) {
        int result = n/div;
        if (div * result < n) {
            ++result;
        }
        return result;
    }
};
```
