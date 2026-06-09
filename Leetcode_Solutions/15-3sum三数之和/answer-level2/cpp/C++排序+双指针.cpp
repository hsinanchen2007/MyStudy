### 解题思路
首先排序，判断边界条件，```size()```小于3直接即可返回
遍历这个vector，选择每次的i+1作为头指针（lo），尾指针（hi）就是向量的最后一个。
不考虑去重的话，那就是如果三者==0，也就是```nums[i]+nums[lo]+nums[hi]==0```的情况，lo和hi都前进一位。如果结果小于0，那就是因为lo过于小，让lo前进一位；大于0则让hi前进一位。
这里还有一个边界条件就是如果```nums[i]==0```，那么直接可以跳出循环了，因为不可能相加等于0。
现在我们考虑去重，当```nums[i]==nums[i-1]```的情况，我们就可以直接跳过本次循环。以及当```sum==0```的情况，判断lo和lo的下一位，hi和hi的下一位，相等就可以无限前进，在代码所示的while循环中，之后再各前进一位到达一个新的不相等的元素。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
		if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;//如果这个元素和上个元素相同
            //就跳过本次循环，去重。
			int lo = i + 1, hi = nums.size() - 1;

			while (lo < hi)
			{
				int sum = nums[i] + nums[lo] + nums[hi];
				if (sum == 0)//如果三者等于0,那么lo和hi同时前进
				{
					ret.push_back({ nums[i],nums[lo],nums[hi] });
					while (lo < hi&&nums[lo] == nums[lo + 1]) lo++;//去重思路都是一样，下一位元素如果一样的话
					while (lo < hi&&nums[hi] == nums[hi - 1]) hi--;//就让对应的指针前进一位

					lo++; hi--;
				}
				else if (sum < 0)//小于0那就是lo不符合条件
				{
					lo++;
				}
				else if (sum > 0)//大于0就是hi不符合条件
				{
					hi--;
				}

			}
		}
		return ret;


        
    }
};
```