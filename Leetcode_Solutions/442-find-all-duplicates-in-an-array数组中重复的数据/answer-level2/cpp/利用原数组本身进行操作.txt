### 解题思路
将入参的nums数组本身当成hashset来使用，假如有数组nums = [4,3,2,7,8,2,3,1]，遍历nums数组，取绝对值abs(nums[i])，abs(nums[i])-1位置的数据设置成负数，即标记了abs(nums[i])数字已经出现过一次；如果abs(nums[i])-1位置的数据本身已经是负数了，则表明这是第二次出现了abs(nums[i])这个数字，则将此数字加入result数组中

### 代码

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int val = abs(nums[i]);
            int changeIndex = val - 1;
        
            if (nums[changeIndex] > 0) {
                nums[changeIndex] *= -1;
            } else {
                res.push_back(val);
            }
            
        }
        return res;
    }
};
```