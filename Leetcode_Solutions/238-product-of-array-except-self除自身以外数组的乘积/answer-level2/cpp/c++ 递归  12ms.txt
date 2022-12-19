### 解题思路
这几天递归写的有点多，看到先想递归。
大体思路是递归阶段不断向下传前面元素的乘积，然后回溯阶段不断返回后面元素的乘积，前后相乘得到当前元素的除自身外数组的乘积。
就是空间复杂度有点高？
![image.png](https://pic.leetcode-cn.com/0bf0edb0fa2b42156152b79c7f016e74ba14ef9b72cc4640fcb717b962edc31f-image.png)

### 代码

```cpp
class Solution {
	public:
		//回溯时后面元素乘积的基数
		int tailRes = 1;

		vector<int> productExceptSelf(vector<int>& nums) 
		{
			vector<int> res(nums.size());
			recurse(nums, 0, 1, res);
			return res;
			
		}
		//参数列表：原数组nums，当前节点索引index，前面元素的乘积preRes，结果数组rs
		int recurse(vector<int>& nums, int index, int preRes, vector<int> &rs)
		{
			//回溯条件，数组索引越界
			if (index >= nums.size())
				return 1;
			//当前元素的除自身外乘积
			//即是递归阶段不断传入的前面元素的乘积，以及回溯时返回的后面元素乘积的乘积
			rs[index] = preRes*recurse(nums, index + 1, preRes*nums[index], rs);
			//返回并同时更新后面元素的乘积，tailRes
			return tailRes = nums[index] * tailRes;
		}
	};
```