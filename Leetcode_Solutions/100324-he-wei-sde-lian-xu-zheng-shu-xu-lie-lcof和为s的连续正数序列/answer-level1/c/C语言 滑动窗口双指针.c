### 解题思路
	滑动窗口的方法这边就不多说了，官方题解有写，这边提一下用C实现的几个坑：
	1、returnSize空间不用申请，后面的returnColumnSizes的第二维列宽需要申请
	2、返回的二维数组的列宽需要动态申请，也就是到用的时候申请滑动窗口大小的列宽，不然大数据时候内存会超出限制
	3、滑动窗口左指针遍历的长度是target/2
### 代码

```c
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes) {
	if (target == 0) {
		*returnSize = 0;
		**returnColumnSizes = 0;
		return 0;
	}

	int midNum = target / 2 + 1;
	int idx = 0;
	int **rtnSeq = (int**)malloc(sizeof(int*) * target);
	int* col = (int*)malloc(sizeof(int) * target);

	for (int i = 1, j = 1; i <= target / 2 + 1;) {
		if ((i + j) * (j - i + 1) / 2 > target) {
			i++;
		}
		else if ((i + j) * (j - i + 1) / 2 < target) {
			j++;
		}
		else {
			// record
            int len = j - i + 1;
			rtnSeq[idx] = (int*)malloc(sizeof(int) * len);
			for (int k = 0; k < len; k++) {
				rtnSeq[idx][k] = i + k;
			}
			col[idx] = len;
			idx++;
			i++;
		}
	}
	*returnColumnSizes = col;
	*returnSize = idx;
	return rtnSeq;
}
```