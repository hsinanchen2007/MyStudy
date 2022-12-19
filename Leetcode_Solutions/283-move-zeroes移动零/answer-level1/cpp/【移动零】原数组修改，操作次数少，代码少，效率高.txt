### 思路
1. 遍历
2. 如果没有遇到0，数字应该在原位置，不用操作
3. 如果遇到了0，这个位置不填入0，应该填入后续的数字
4. 记录这个位置，下次遇到不是0的数字时，拷贝新数字到这个位置
5. 然后把这个位置增加，等待再下一个不是0的数字
6. 一旦遇到过0，后续不是0的数字都需要拷贝到新位置
6. 遍历之后，把空出来的位置改写成0

```C++
void moveZeroes(vector<int>& nums)
{
	size_t j = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0) continue;
		if (i == j++) continue;
		nums[j - 1] = nums[i];
	}
	for (; j < nums.size(); j++)
	{
		nums[j] = 0;
	}
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

