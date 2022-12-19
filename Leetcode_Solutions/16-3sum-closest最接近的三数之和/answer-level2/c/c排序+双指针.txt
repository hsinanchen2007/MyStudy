### 解题思路
照着大佬的代码写的

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
	qsort(nums,numsSize,sizeof(nums[0]),cmp);
	int ans = nums[0]+nums[1]+nums[2];
	for(int i=0; i<numsSize; i++){
		int start = i+1,end = numsSize-1;
		while(start<end){
			int sum = nums[start] + nums[end] + nums[i];
			if(fabs(target - sum)<fabs(target - ans))
				ans = sum;
			if(sum>target)
				end--;
			else if(sum<target)
				start++;
			else return ans;
		}
	}
	return ans;
}
```