一开始想一次遍历解决问题，结果反而复杂了。
因为数组元素中存在负数，如果直接使用负数标记，那么会引起混乱。
因此一开始想的是，维护一个队列暂时存放不能标记的索引。
而题目要求常数级别的空间，所以这个队列只能在原数组中暂存。
```
int firstMissingPositive(int* nums, int numsSize){
	
	int top = 0, tail = 0;
	int cur = 0;
	
	while(cur < numsSize)
	{
		if(nums[cur] > 0 && nums[cur] <= numsSize)
		{
			if(cur >= (nums[cur] - 1))
			{
                if(nums[nums[cur] - 1] > 0)//不能重复标记
                {
                    nums[nums[cur] - 1] *= (-1);
                }
			}
			else
			{
				nums[tail++] = nums[tail] > 0 ? (nums[cur] - 1) : -(nums[cur] - 1);
			}
		}
		else
		{
			nums[cur] = INT_MAX;
		}
		cur++;
	}
	while(top < tail)
	{
		int index = nums[top] > 0 ? nums[top] : -nums[top];
        if( nums[index] > 0) //不能重复标记 
        {
            nums[index] *= -1;
        }
        
        top++;
	}
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] > 0)
		{
			return i + 1;
		}
	}


    return numsSize + 1;
}
```
看完题解，先把负数去除，再标记
```
int firstMissingPositive(int* nums, int numsSize){
	
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] <= 0)
		{
			nums[i] = numsSize + 1;
		}
	}

	for(int i = 0; i < numsSize; i++)
	{
        int index = abs(nums[i]);
		if(index <= numsSize && nums[index - 1] > 0)
		{
			nums[index - 1] *= (-1);
		}
	}
    
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] > 0)
		{
			return i + 1;
		}
	}
	
	return numsSize + 1;
}
```

