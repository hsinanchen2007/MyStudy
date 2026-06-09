![image.png](https://pic.leetcode-cn.com/61c153bd0b098d4fedbb6654fc50a31e4563779ccb2712de55ee505fd6033100-image.png)
### 解题思路
利用[31.下一个排列](https://leetcode-cn.com/problems/next-permutation/solution/c-0msjian-dan-shi-xian-by-lcl-17/)的结论实现，超简单！
因为nums列表无重复, 故组合总数为n!

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
        int count = 1;
        for(int i = 1;i <= nums.size(); i++) count *= i;
		for(; count > 0; count--){
			nextPermutation(nums);
			res.push_back(nums);
		}
		return res;
	}
    void nextPermutation(vector<int>& nums) {
		int pos = nums.size() - 1;
        vector<int>& ans = nums;
		while (pos > 0 && nums[pos] <= nums[pos - 1])
			pos--;
		reverse(nums.begin() + pos, nums.end());  //逆序
		if (pos > 0){
			int start = pos;
			for (; start < nums.size(); start++){ //寻找第一个大于nums[pos - 1]的数
				if (nums[start] > nums[pos - 1]){
					swap(nums[start], nums[pos - 1]); //交换
					break;
				}
			}
		}
	}
};
```