
第一层用i遍历数组，第二层用j遍历数组，其中j=i+1然后逐步递增，查看数组里有没有可以相加和为target的两个元素
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *res = (int*)malloc(sizeof(int)*2);
	*returnSize = 2;
	int i;
	int j;
	for(i=0;i<numsSize;i++){
		for(j=i+1;j<numsSize;j++){
			if( nums[i]+nums[j]==target){
				res[0]=i;
				res[1]=j;
			}
		}
	}
	return res;
}
```
