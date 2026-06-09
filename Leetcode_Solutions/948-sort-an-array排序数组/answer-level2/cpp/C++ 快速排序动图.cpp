自己做的小动画，其实网上已经有很多动画了，只是为了让我自己能记住。

![ppt27C1.pptm  -  已自动恢复.gif](https://pic.leetcode-cn.com/d98bdfca9931a748e515ab1f8525c6db7dbec94ea8e87f3b9a53786039411b13-ppt27C1.pptm%20%20-%20%20%E5%B7%B2%E8%87%AA%E5%8A%A8%E6%81%A2%E5%A4%8D.gif)

```cpp
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivot = l+rand()%(r-l);
        swap(nums[pivot], nums[r]);
        int i = l; // nums[i-1] 必定小于 nums[r]
        for (int j = l; j < r; j++) {
            if (nums[j] < nums[r]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        quick_sort(nums, l, i-1);
        quick_sort(nums, i+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
```