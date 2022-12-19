### 解题思路
摩尔投票这么神奇的嘛..    自己的算法真是菜啊

### 代码

```c
int majorityElement(int* nums, int numsSize)
{
	int count = 0, ans = 0;
	
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[ans] == nums[i])
		count++;
		else
		count--;
		
		if(count == 0)
		ans = i+1;
		
		if(count > numsSize/2)
		break; 
	}
	return nums[ans];
}
```