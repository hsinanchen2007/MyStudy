双指针滑动窗口
tail先向后走，以期使和大于等于s,
滑动窗口元素的和 等于等于s时，head向前走， 以减少长度。
```
#define MIN(X,Y)(X < Y ? X : Y)
int minSubArrayLen(int s, int* nums, int numsSize){
	
	int ret = INT_MAX;
	int head = 0, tail = 0;
	int temp = 0;
	
	while(tail <= numsSize) // 当tail ==numsSize时，仍然需要进行检查
	{
		while(temp >= s && head < tail)
		{
			ret = MIN(ret, tail - head);
			temp -= nums[head++];
		}
		
        if(tail == numsSize)
        {
            break;
        }

		temp += nums[tail++]; 
	}
	
	return ret == INT_MAX ? 0 : ret;
}
```
题目还问了O(NlogN)的解法
和滑动窗口的思路其实是一样的，先找到满足题目条件 >= s 的子数组， 再想办法缩短子数组的长度
```
#define MIN(X,Y)(X < Y ? X : Y)
int minSubArrayLen(int s, int* nums, int numsSize){
	
    if(numsSize == 0)
    {
        return 0;
    }
	int dp[numsSize]; // dp[i] 为 从 [0,i]中的元素之和， dp[j] - dp[i] 为 (i,j]的元素之和。
	int ret = INT_MAX;
	
	for(int i = 0, temp = 0; i < numsSize; i++)
	{
		temp += nums[i];
		dp[i] = temp;
	}
	
	for(int i = 0; i < numsSize; i++)
	{
		if(dp[i] >= s) // 此时 [0,i]中存在子数组， 且子数组右边界为i，现在找左边界。 左边界满足条件 dp[i] - dp[k] >= s, 数组为(k,i] 长度为 i - k
		{
			int left = 0, right = i;	
            int mid =  0;
			
            ret = MIN(ret, i + 1); //左边界为-1
			
			while(left < right)
			{
                mid = left + ((right - left + 1) >> 1);
				
                if(dp[i] >= dp[mid] + s)
				{
					left = mid;
				}
				else
				{
					right = mid - 1;
				}
			}
			
			if(dp[i] >= dp[right] + s)
			{
				ret = MIN(ret, i - right);
			}
			
		}
	}
	
	return ret == INT_MAX ? 0 : ret;
}
```
