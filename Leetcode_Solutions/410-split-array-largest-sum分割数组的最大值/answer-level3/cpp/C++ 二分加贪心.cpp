参考官方题解的答案，使用了二分加贪心。本来还想二分应该怎么做的，没想到是抓住了和的最大值这个点。
每组和的最大值越大，可以分的组就可以越少，越可以满足题目的分组数目m。当和的最大值越小的时候，需要分的组数就越大，超过了m的时候就不满足需求了，这样就必须加大和的最大值。

分组这里使用了贪心算法，每个组都力求加满到最大值，这个又刚好符合了让分组数目越少的要求。

当和的最大值二分逼近的时候，我们就找到了答案。

初始的l选择了数组里面的最大值，因为它是个隐藏条件。r则选择了数组的所有元素和，意味着只分1组。

```
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long l = 0;
        long long r = 0;
        
        for (auto n : nums) {
            r = r+n;
            if (l < n) {
                l = n;
            }
        }
        long long res = r;
        while (l <= r) {
            long long mid = l + ((r - l) >>1);
            int cut = 1;
            long long sum = 0;
            for (auto n : nums) {
                if (sum + n <= mid) {
                    sum += n;
                } else {
                    cut++;
                    sum = n;
                }
            }
            if (cut<=m) {
                res = min(res, mid);
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
```