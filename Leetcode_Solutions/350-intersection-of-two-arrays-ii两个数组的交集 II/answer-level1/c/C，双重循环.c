### 解题思路
如果两个数相等，那么这个数就从两个数组中删除，进入要返回的数组
即用nums2的数组元素和num1的数组元素进行比较，如果相同，则在下次循环的时候将该元素从nums2中剔除（用nums2的最后一个元素将其覆盖）

### 代码

```c
#include<stdio.h>
#include<stdlib.h>


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	*returnSize = nums1Size > nums2Size ? nums1Size : nums2Size;
	int *a = (int *)calloc((*returnSize + 1), sizeof(int));
	int size = 0;
	int k = 0;
		for (int i = 0; i < nums1Size; i++) {
			for (int j = 0; j < nums2Size; j++) {
				if (nums1[i] == nums2[j]) {
					a[size] = nums1[i];
					nums2[j] = nums2[nums2Size - 1];
					nums2Size--;
					size++;
					break;
				}
			}
		}


	*returnSize = size;
	return a;
}
```