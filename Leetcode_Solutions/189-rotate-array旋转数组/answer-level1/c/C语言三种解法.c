### 解题思路
C语言
解法一：空间换时间
解法二：一个一个移，力扣不知道为什么时间超出限制
解法三：数组分成2半各自原地交换，再总的交换一次
### 代码
解法一：空间换时间
```c
void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
	int* nums1 = (int*)malloc(4 * numsSize * 2);
	assert(nums1);
	int i = 0;
	while (i < numsSize)
	{
		nums1[i] = nums[i];
		i++;
	}
	i = 0;
	while (i < numsSize)
	{
		nums1[i+ numsSize] = nums[i];
		i++;
	}
	int j = 0;
	i = numsSize - k;
	while (j < numsSize)
	{
		nums[j] = nums1[i];
		i++;
		j++;
	}
	free(nums1);
}

```
解法二：一个一个移，力扣不知道为什么时间超出限制
```
 void moveOneR(int *nums,int numsSize)
 {
     int last = nums[numsSize-1];//记录最后一个值
     int cur = numsSize-1;
     while(cur)
     {
         nums[cur] = nums[cur-1]; 
         cur--;
     }
     nums[0] = last;
 }
 void rotate(int* nums, int numsSize, int k){
     while(k--)
     {
         moveOneR(nums,numsSize);
     }
 }
```
解法三：数组分成2半各自原地交换，再总的交换一次
```
 void reverse(int* left, int* right)//左右交换left--right的内容
 {
 	while (left < right)
 	{
 		int chip = *right;
 		*right = *left;
 		*left = chip;
 		left++;
 		right--;
 	}
 }
 void rotate(int* nums, int numsSize, int k) {
 	reverse(nums, nums + numsSize - k%numsSize-1);//0--k-1交换
 	reverse(nums + numsSize-k%numsSize, nums + numsSize - 1);//k-len-1交换
 	reverse(nums, nums + numsSize - 1);//0--len-1交换
 }
```