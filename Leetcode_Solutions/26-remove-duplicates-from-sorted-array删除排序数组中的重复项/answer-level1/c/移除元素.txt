### 解题思路
首先判空，再依次遍历，因为已经排序啦，所以之后出现的数不会重复，找到之后按序赋值即可

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
	int i, j=1;
    if (numsSize == 0) j=0;
    for(i=0;i<numsSize-1;i++) {
    	if (nums[i] != nums[i+1]) {
    		nums[j] = nums[i+1];
    		j++;
		}
	}
	return j;
}
```