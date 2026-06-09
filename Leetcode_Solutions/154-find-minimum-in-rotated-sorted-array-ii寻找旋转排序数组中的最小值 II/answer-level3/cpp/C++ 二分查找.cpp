## 思路
- 基本跟153差不多
- 去重即可   即代码中`--r`
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if(nums[0] < nums[r])  return nums[0];
        while(l + 1 < r){
            int mid = l + (r - l)/2;
            if(nums[mid] < nums[r])    r = mid;
            else if(nums[mid] > nums[r])   l = mid;
            else{
                -- r;
            }
        }
        return nums[r];
    }
};
```
