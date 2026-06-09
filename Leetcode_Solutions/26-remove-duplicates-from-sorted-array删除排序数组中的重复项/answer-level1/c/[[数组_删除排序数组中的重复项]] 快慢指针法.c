fast指针用于遍历每个元素，slow指针指向无重复的最后一个元素。

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
	int slow=0,fast;
	for(fast=1;fast<numsSize;fast++){
		if(nums[fast]!=nums[slow]){
			nums[++slow]=nums[fast];
		}		
	}
	return slow+1;
}
```