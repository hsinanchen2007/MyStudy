```cpp []
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }

    int majorityElement(vector<int>& nums, int lptr, int rptr) {
        if(lptr == rptr) return nums[lptr];

        int mid = (lptr + rptr) / 2;
        int left = majorityElement(nums, lptr, mid);
        int right = majorityElement(nums, mid + 1, rptr);

        if(left == right) return left;

        int leftCount = 0;
        int rightCount = 0;
        for(int i = lptr; i < mid; i++) if(left == nums[i]) leftCount++;
        for(int i = mid; i < rptr; i++) if(right == nums[i]) rightCount++;
        return leftCount > rightCount ? left : right;
    }
};
```

