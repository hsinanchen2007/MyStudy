k-sum问题的统一解法
1. 固定 k-2 个数
2. 双指针遍历求和

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2], n = nums.size();
        for (int i = 0; i < n; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int tmp = nums[i] + nums[low] + nums[high];
                if (abs(target - tmp) < abs(target - ret))
                    ret = tmp;
                if (tmp < target)
                    low++;
                else if (tmp > target)
                    high--;
                else
                    return target;
            }
        }
        return ret;
    }
};
```

- 时间复杂度 $O(n^2)$ （双指针也是遍历一遍数组），排序 $O(nlog_2^n)$, 总的时间复杂度 $O(nlog_2^n)+O(n^2)=O(n^2)$
- 空间复杂度$O(1)$