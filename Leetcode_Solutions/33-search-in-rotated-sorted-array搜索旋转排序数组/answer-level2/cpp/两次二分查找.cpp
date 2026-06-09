```C++ []
class Solution {
public:
    int find(vector<int>& nums, int left, int right){
        if(nums[left] < nums[right])
            return 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1])
                return mid + 1;
            if(nums[mid] >= nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }
    
    int binsearch(vector<int>& nums, int left, int right, int target){
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return - 1;
        if(n == 1) return nums[0] == target? 0: -1;
        int start = find(nums, 0, n - 1);
        if(nums[start] == target) return start;
        if(start == 0) return binsearch(nums, 0, n - 1, target);
        if(target < nums[0]) return binsearch(nums, start, n-1, target);
        return binsearch(nums, 0, start, target);
    }
};
```
两次二分查找就可以了，一次来找到起始的位置，一次来朝着目标。书写二分查找的时候必须注意，**因为right = mid - 1，并且，mid = (left + right) / 2,因为实际上会出现右侧边界取不到的情况，因为在判断的时候一定要加上等号。
