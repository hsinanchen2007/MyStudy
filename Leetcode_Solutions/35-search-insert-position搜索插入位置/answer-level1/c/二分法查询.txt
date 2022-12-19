### 解题思路

![image.png](https://pic.leetcode-cn.com/60982e1a828f431ce9abf9a6224578e4fc423a832ebd43e2b3827f8646ef64ac-image.png)

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){

	int left = 0, right = numsSize - 1;    //使用二分法查询，定义两个指针，分别指向要查询的左边与右边。

	while(left <= right){    //如果左指针大于了右指针，那就说明没找到，插入的位置应该是左右指针之间，此时插入位置应该为较大的左指针。
		if (nums[(left + right)/2] > target)    //比目标值大，那就去左边找，调整右指针
			right = (left + right)/2 - 1;
		else if (nums[(left + right)/2] < target)    //比目标值小，那就去右边找，调整左指针
			left = (left + right)/2 + 1;
		else    //相等，直接返回
			return (left + right)/2;
	}

	return left;

}
```