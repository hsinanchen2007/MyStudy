### 解题思路
首先题目要求常数级别的空间复杂度，这个时候首先想到指针，使用双指针法可以解决这个问题。由于数组是有序的，所以我们用两个指针，第一个指针指向第一个元素，第二个指针指向第二个元素。用第二个指针遍历数组，如果发现第二个指针指向元素的值大于第一个指针指向元素，这个时候将第一个指针向后移动一个元素，然后修改第一个指针指向的元素，直到for循环完成。
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
    //先处理特殊情况，否则会产生执行错误
	if (nums.size() == 0)  //所给数组为空
		return 0;
	auto itr1{ nums.begin() };  //指针1指向第一个元素
	auto itr2{ nums.begin() + 1};  //指针2指向第二个元素
	for (itr2; itr2 != nums.end(); ++itr2)  //遍历数组
	{
		if (*itr2 > * itr1)  //发现和指针1不相同的数
		{
			itr1 += 1;  //指针1向后移动一个元素
			*itr1 = *itr2;  //修改指针1的值
		}
	}
	return itr1 - nums.begin() + 1;  //返回数组长度
    }
};
```