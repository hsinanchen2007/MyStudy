### 解题思路
开始使用的是双指针，结果发现测试用例中存在返回值为0的情况。针对这种情况，对程序进行了修改。
1、先对```nums[1] ~ nums[N-1]```进行求和sum;
2、如果sum为0，则直接返回0（针对特殊用例）
3、如果sum不为0，定义```head==1，left = nums[0]```；然后while循环逐次向右移动并比较left和sum。

### 代码

```c
int pivotIndex(int* nums, int numsSize){
	if(numsSize < 3)
	{
		return -1;
	}
	int i = 0;
	int sum = 0;
	for ( i = 1; i < numsSize; i++) 
	{
		sum += nums[i];
	}
	if(sum == 0)
	{
		return 0;
	}
	else
	{
		int head = 1;
		int left = nums[0];
		while(head < numsSize)
		{
			sum -= nums[head];
			if(left == sum)
			{
				return head;
			}
			else
			{
				left += nums[head];
				head++;
			}
		}
	}
	return -1;


}
```