```
/* 我有点疑惑，对于numsSize我已经试了出来，最大是6，也就是说，申请数组最小得是720个，那我的内存消耗在哪里了？
为什么内存上我只是超过了百分之五十多？，有没有哪位了解的告诉一下 */
void swap(int* nums, int a,int b) {
	int temp = nums[a];
	nums[a]= nums[b];
	nums[b]= temp;
}
void  backtrack(int* nums,int numsSize,int** ret,int first,int* returnSize, int** returnColumnSizes) {
	if(first==numsSize) {
		returnColumnSizes[0][*returnSize]=numsSize;
        ret[*returnSize] = (int*)calloc(numsSize,sizeof(int));
		memcpy(ret[*returnSize],nums,numsSize*sizeof(int));
		(*returnSize)++;
		return;
	}
	int  i;
	for(i=first; i<numsSize; i++) {
		swap(nums,first,i);
		backtrack(nums,numsSize,ret,first+1,returnSize,returnColumnSizes);
		swap(nums,first,i);
	}
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** ret=(int **)calloc(720,sizeof(int *));
	returnColumnSizes[0]=(int*)calloc(720,sizeof(int)) ;
	*returnSize=0;
	backtrack(nums,numsSize,ret,0,returnSize,returnColumnSizes);
	return ret;
}
```