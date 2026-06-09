```cpp
class Solution {

private: 
    int getFirstTarget(const vector<int> & nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                if (mid - 1 >= 0 && nums[mid-1] == target) // 比常规二分法多了这句
                    r = mid - 1;
                else
                    return mid;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }


   int getLastTarget(const vector<int> & nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                if (mid + 1 <= r && nums[mid+1] == target)  // 比常规二分法多了这句
                    l = mid + 1;
                else
                    return mid;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        
        // 一句解决
        // return upper_bound(nums.begin(), nums.end(), target) - 
        //     lower_bound(nums.begin(), nums.end(), target);
        
        if (nums.size() == 0)
            return 0;
        int fistIndex = getFirstTarget(nums, target);  //二分查找第一个target
        if (fistIndex == -1) return 0;
        int lastIndex = getLastTarget(nums, target);  //二分查找最后一个target
        return lastIndex - fistIndex + 1;

    }
};
```