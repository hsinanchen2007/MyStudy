# 137. 只出现一次的数字 II
**思路：**
- 先使用sort()函数对传入数组进行排序。获得一个有序序列。
- 再遍历该序列，如果遍历的点以下各节点为空或者与本节点值不相等，则该节点值就位只出现一个的数字，否则节点向后移动3步，寻找下一个节点。

**代码：**
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
		for(int i = 0; i < nums.size(); i+=3){
			if(	((i+1) == nums.size()) || (nums[i]!=nums[i+1]) ){
				return nums[i];
			}
		}
		return nums[nums.size()-1];
    }
};
```


 