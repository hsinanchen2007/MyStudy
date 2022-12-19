执行用时 :
108 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
14.2 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int len=nums.size();
		for(int i=1;i<len;++i)
			if(nums[i-1]==nums[i]) return nums[i];
		return -1;
    }
};
```