暴力法

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *p=NULL;
	p=(int*)malloc(sizeof(int)*2);
	int i,j;
	for(i=0;i<numsSize-1;i++){
		for(j=i+1;j<numsSize;j++){
			if(nums[i]+nums[j]==target){
				*returnSize=2;
				p[0]=i;
				p[1]=j;
			}
		}
	}
	return p;
}
```