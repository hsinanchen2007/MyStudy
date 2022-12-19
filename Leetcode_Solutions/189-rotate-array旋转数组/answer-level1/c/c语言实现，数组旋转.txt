思路：通过元素k，数组分为两部分，然后对这两部分分别逆置，最后对整个数组逆置。

例如：
[1,2,3,4,5]   k =3

![image.png](https://pic.leetcode-cn.com/6be41195ac1825b5caa7ca535342d07c043cc6c0b7e87fe3a856c9f6677d946f-image.png){:width=600}

```C []
void rotate(int* nums, int numsSize, int k){
	int i = 0;
	int tmp = 0;
	int j = 0;
    k %= numsSize;//只需要旋转小于numsSize的长度
	for (i = 0, j = numsSize - 1 - k; i<j; i++, j--)//对前半部分逆置
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--)//对后半部分逆置
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = 0, j = numsSize-1; i<j; i++, j--)//对整体数组逆置
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

}

```