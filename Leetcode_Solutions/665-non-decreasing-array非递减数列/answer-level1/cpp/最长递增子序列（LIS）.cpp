直接 dp 会超时，这个解法时间复杂度是 O(nlgn)
```
class Solution {
private:
    int lis(const vector<int> &nums){
        vector<int> helper(nums.size());
        helper[0] = nums[0];
        int len = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]>=helper[len-1])
                helper[len++] = nums[i];
            else{
                int pos = binarySearch(nums, len, nums[i]);
                helper[pos] = nums[i];
            }
        }
        return len;
    }
    int binarySearch(const vector<int> &nums, int len, int x){
        int low = 0, high = len - 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==x)  return mid;
            else if(nums[mid]>x)  high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
public:
    bool checkPossibility(vector<int>& nums) {
        return lis(nums)>=nums.size()-1;
    }
};
```
