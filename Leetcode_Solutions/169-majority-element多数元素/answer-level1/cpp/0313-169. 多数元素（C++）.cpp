### 解题思路
次数大于N/2的元素，一定在size / 2 的索引出出现

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());       
        return nums[size / 2];
       
    }
};
```