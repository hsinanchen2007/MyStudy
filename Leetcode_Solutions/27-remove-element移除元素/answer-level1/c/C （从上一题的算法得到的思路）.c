### 解题思路
此处撰写解题思路
最好的用时是4ms
最少的内存消耗是：7.2MB
总体来说，刚看到题目时第一时间想到的就是上一题。框架写出来倒是很简单，但是还是有一些细节做的不好，浪费了很多时间。
空的情况好像不用考虑（虽然我加了特殊语句，但是删了应该也行，一会试试有改善吗），主要是numsSize有可能是负的情况，本来想的是返回值的时候
如果是负的就返回0，但是对于【2，3，3】 3 这种情况就不适用，因为他虽然没有变成负的，但是会返回0。后来想到，是因为代码中间比较的时候
有可能和自身比较，导致numsSize多自减一次，后在while中加了判断就可以了。
开始不确定用神魔作为返回值，就又定义了一个没后来想了想还是得用numsSize，因为有i<numsSize的判断，说明结束时，numsSize是符合的，
如果再用一个我会比较混乱。
再去看看大佬的解法，看完再总结。
### 代码

```c
int removeElement(int* nums, int numsSize, int val) {
	int i = 0;
	if (numsSize == 1 && val == nums[0])
		return 0;
	while (i < numsSize)
	{
		if (nums[i] == val)
		{
			while (nums[numsSize - 1] == val&&numsSize-1 > i)
			{
				numsSize--;
			}
			nums[i] = nums[numsSize - 1];
			numsSize--;
		}
		i++;
	}
	return numsSize;
}
```