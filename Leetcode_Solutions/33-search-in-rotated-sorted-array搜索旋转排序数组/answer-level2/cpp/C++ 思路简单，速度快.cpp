### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //vector<int> nums1(nums);
        vector<int>::iterator it = min_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int exc = it - nums.begin();
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(target == nums[mid]) return (mid + exc) % nums.size();
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;        
    }
};
```