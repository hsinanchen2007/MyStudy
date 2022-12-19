### 解题思路
见到此题，首先想到了之前做过的跳台阶和斐波那契数列。
先用了递归试了一下，自己的几个例子都能通，但用在LeetCode上果然是不行，69个测试案例，只通过了59个，显示超时。
这时想到递归方法中存在很多重复计算，因此需要使用更节省计算量的方法。
把前两项计算出来然后递推得到后面的项，可以避免重复计算。
通过这个题，真的深切体会到递归真的费时，能不用尽量不要用。

### 代码

```cpp
class Solution {
public:
int rob(vector<int>& nums) {
	int size = nums.size();
	vector<int> temp;
	if (size == 0)
		return 0;
	if (size == 1)	
		return nums[0];
	if (size == 2)
		return nums[0] > nums[1] ? nums[0] : nums[1];
	if (size >= 3)
	{
		int result = 0;
		temp.push_back(nums[0]);
		temp.push_back(nums[0] > nums[1] ? nums[0] : nums[1]);
		int bigger;
		for (int i = 2; i < size; i++)
		{
			bigger = temp[i - 1] > (temp[i - 2] + nums[i]) ? temp[i - 1] : (temp[i - 2] + nums[i]);
			temp.push_back(bigger);
		}
		return temp.back();
	}
	return 0;
}
};
```