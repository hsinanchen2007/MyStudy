### 解题思路
参考官方，解法很巧妙

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i])-1;
            if (nums[index] > 0) {
                nums[index] = nums[index] * (-1);
            } 
        }
        for(int i = 1; i <= nums.size(); ++i) {
            if (nums[i-1] > 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
```