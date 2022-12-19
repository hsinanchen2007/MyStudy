### 解题思路
此处撰写解题思路

### 代码

```c

void quick_sort(int s[], int l, int r)
{
	int i = l, j = r, base = s[i]; 
	if(l < r)
	{
		while(i < j)
		{
			while(i < j && s[j] > base)
			j--;
			
			if(i < j)
			s[i++] = s[j];
			
			while(i < j && s[i] < base)
			i++; 
			
			if(i < j)
			s[j--] = s[i];
		} 
		
		s[i] = base;
		
		quick_sort(s, l, i-1);
		quick_sort(s, i+1, r); 
	} 
}


int* sortArray(int* nums, int numsSize, int* returnSize)
{
	quick_sort(nums, 0, numsSize-1);
	
	*returnSize = numsSize;
	return nums;
}
```