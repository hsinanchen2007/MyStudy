```
class Solution {
public:
    int binaryFindMin(vector<int>& nums, int left, int right){
        if(left == right)
            return left;
        else
        {
            if(nums[right] > nums[left])
                return left;
            int mid = left + (right - left)/2;
            if(mid == 0)
                return 1;
            else if(nums[mid-1]>nums[mid] && nums[mid+1] > nums[mid])
                return mid;
            else if(nums[mid] > nums[0])
                return binaryFindMin(nums, mid+1, right);
            else
                return binaryFindMin(nums, left, mid-1);
        }
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int index = binaryFindMin(nums, 0, n-1);
        return nums[index];
    }
};
```
