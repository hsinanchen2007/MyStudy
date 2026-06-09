### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {            	
        std::sort(nums.begin(), nums.end());
    	size_t i = 0;
    	while(i <= nums.size()-1)
    	{
    		if(i == nums.size()-1) return nums[i];
    		if(nums[i]==nums[i+1]){
    			i+=3;
    			continue;
    		}else{
    			return nums[i];
    		}
    	}
    	return nums[0];
    }
};
```