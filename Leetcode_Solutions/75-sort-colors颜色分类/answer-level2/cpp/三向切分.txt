### 解题思路
每次计算，可以将数组分为三部分，一部分小于v，一部分等于v，一部分大于v

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        mysort(nums, 0, nums.size()-1);
    }

    void mysort(vector<int>& nums, int lo, int hi)
    {
        if(lo >= hi) return;
        int gt = hi;
        int lt = lo;
        int i = lo + 1;
        int v = nums[lo];

        while(i <= gt)
        {
            if(nums[i] < v) exch(nums, i++, lt++);
            else if(nums[i] > v) exch(nums, i, gt--);
            else i++;
        }

        if(v == 2) mysort(nums, lo, lt-1);
        if(v == 0) mysort(nums, gt+1, hi);
    }

    void exch(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
```