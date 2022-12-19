
```
#define MAX(X,Y) (X > Y ? X : Y)
#define MIN(X,Y) (X < Y ? X : Y)

int findUnsortedSubarray(int* nums, int numsSize){

    if(numsSize == 1)
    {
        return 0;
    }
	
	int min = INT_MAX;
	int max = INT_MIN;
	int left, right;
	
	for(int i = 1; i < numsSize; i++)
	{
		if(nums[i] < nums[i - 1]) 
		{
			min = MIN(min, nums[i]);
			max = MAX(max, nums[i - 1]);
		}
	}
	
	if(max == INT_MIN || min == INT_MAX)
	{
		return 0;
	}
	
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] > min)
		{
			left = i;
            break;  //找到了就得退出。
		}
		
	}
	
	for(int j = numsSize - 1; j >= 0; j--)
	{
		if(nums[j] < max)
		{
			right = j;
            break;
		}
	}
    
	return right - left + 1;
}
```
