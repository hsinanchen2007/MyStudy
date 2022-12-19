思路：先翻转一下思路，第k小，就是至少需要有k个 距离小于等于某个数M 的距离对。这个数M越大的话，小于M的距离对就会越多，反之越少。这里就符合了二分的思想。
可以把距离M作为二分的所求变量。true的条件为当M的条件下，小于M的距离对个数需要大于k。否则就是不满足条件。此时你会发现当求解之后，M刚好也是第k小的距离，因为它是最适合的令小于M距离的距离对个数为k个的最小值。

另外一个点在于当M一定的时候，怎么求小于M的距离对，这里也挺取巧的，先对数组从小到大进行排序，对某个nums[right]=a，从left=0开始算，直到nums[right]-nums[left]<=M的时候，right-left就是 小于M的距离对 个数。从0遍历right，就能得到所有 小于M的距离对 个数。此外，因为right是从小遍历，left可以保持上一次的值，不需要从0开始遍历。因为right增加之后，nums[right]一定是增加或相等的。left就可以继续接着递增判断。
```
class Solution {
public:
    int smallestDistancePair2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int l = 0;
        int r = nums[size - 1] - nums[0];
        while (l < r) {
            int mid = l + ((r-l) >>1);
            int count = 0;
            int left = 0;
            for (int right=0; right<size; right ++) {
                while(nums[right] - nums[left] > mid) left++;
                count += right - left;
            }
            if (count >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```