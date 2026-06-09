### 解题思路
每次遇到等于val的元素k递增，遇到不是val的元素往前移动k个位置，最后返回数组有效长度numsSize-k,有效长度后面的数据不用管。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
	if(numsSize<1) {
		return numsSize;
	}
	int k=0;
	for(int i=0;i<numsSize;i++) {
		if(nums[i]==val) {
			k++;
		} else {
			nums[i-k]=nums[i];
		}
	}
	return numsSize-k;
}
```