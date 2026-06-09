### 解题思路
![Snipaste_2020-03-28_15-18-30.jpg](https://pic.leetcode-cn.com/95e152e2fc448f9f1389a390f14f2212582e0f1a481747e8e84f3639c61d76a1-Snipaste_2020-03-28_15-18-30.jpg)

比较相邻两个数,从下标1开始覆盖

### 代码

```c
int removeDuplicates(int* nums,int numsSize){
    if(numsSize<=1) return numsSize;
	int i=0,count=1;
	for(i=0;i<numsSize-1;i++){
		if(nums[i]!=nums[i+1]){
			nums[count]=nums[i+1];
			count++;
		}
	}
	return count;
}
```