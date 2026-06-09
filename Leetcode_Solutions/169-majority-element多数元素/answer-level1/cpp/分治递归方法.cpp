### 解题思路
方法肯定不是最快最好的，20ms，12.7MB。
只是在这分享一下思路，求大家批评指点。
首先取出input数组的第一个元素nums[0]，再遍历input数组后面所有元素，并把所有大于nums[0]和小于nums[0]的元素分别放入两个新数组smaller和bigger中。观察smaller和bigger数组的长度，如果其中一个长度大于输入数组的一半，则直接对其调用原函数。如果smaller和bigger数组长度都不足输入数组的一半，则这时nums[0]就是要寻找的出现超过一半的元素。
### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
	int size = nums.size();
	int first = nums[0];
	vector<int> smaller;
	vector<int> bigger;
	for (int i = 1; i < size; i++)
	{
		if (nums[i] < first)
			smaller.push_back(nums[i]);
		if (nums[i] > first)
			bigger.push_back(nums[i]);
	}
	int size_small = smaller.size();
	int size_big = bigger.size();
	if (size_small > size / 2)
		return majorityElement(smaller);
	else
	{
		if (size_big > size / 2)
			return majorityElement(bigger);
		else
			return first;
	}
}
};
```