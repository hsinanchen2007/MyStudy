
只遍历依次。从前往后记录某个元素前面重复元素个数，遇到第一个不相同元素那就将这个元素移动到前面去。后面的相同元素就只统计数目不移动。
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	int dupLen = 0;
	int length = nums.size();
	for (int i = 1; i < length; i++)
	{
		if (nums[i] == nums[i - 1])
		{
			dupLen++;
		}
		else {
			nums[i - dupLen] = nums[i];
		}
	}

	return length-dupLen;
}
};
```
更多有趣算法教程请看：[知乎@司南牧](https://www.zhihu.com/people/yuanmuou/activities)