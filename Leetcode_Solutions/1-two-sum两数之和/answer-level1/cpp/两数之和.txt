### 解题思路
因为看了不可重复，所以考虑了一下元素剔除，效率不高。继续学习！！
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vecRet;
	    for(int i = 0; i < nums.size() - 1; i++)
	    {
		    for(int j = i + 1; j < nums.size(); j++)
		    {
			    if(nums[i] + nums[j] == target)
			    {
				    vecRet.push_back(i);
				    vecRet.push_back(j);
				    nums.erase(nums.begin() + i);
				    nums.erase(nums.begin() + j - 1);
				    return vecRet;
			    }
		    }
	    }
        return vecRet;
    }
};
```