先找到旋转点，再分别二分
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[left]){
                left = mid;
            }else{
                right = mid;
            }
        }
        int ans = binSearch(nums, 0, left, target);
        return ans == -1 ? binSearch(nums, left+1, nums.size()-1, target) : ans;
    }
    int binSearch(vector<int>& nums, int left, int right, int target){    
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};
```
