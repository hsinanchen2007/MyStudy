### 解题思路
执行用时 :88 ms, 在所有 C++ 提交中击败了26.24% 的用户
内存消耗 :19.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
    	map<int, int> nums_record;
    	for(size_t i=0;i<nums.size();++i){
    		nums_record[nums[i]]++;
    		if(nums_record[nums[i]] > 1) return nums[i];
    	}
    	return -1;
    }
};
```