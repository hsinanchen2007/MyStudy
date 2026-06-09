### 解题思路
此处撰写解题思路
i循环取数，j循环依次将后面的每个元素对比，一样就用k循环删除数组后面的元素，长度减一
### 代码

```c
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
	int i,j,k;
	for(i = 0; i < numsSize-1; i ++){
		for(j = i + 1; j < numsSize;){
			if(nums[i] == nums[j]){
				for(k = j; k < numsSize -1; k ++){
					nums[k]=nums[k+1];
				}
				numsSize --;
			}
		    else j ++;
		}
	}
	return numsSize;
}
```