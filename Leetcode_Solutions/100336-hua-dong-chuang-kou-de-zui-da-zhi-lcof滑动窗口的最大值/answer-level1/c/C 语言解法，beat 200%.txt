
![image.png](https://pic.leetcode-cn.com/6171e6d4a480a5c4e5a676f396dc8787721d4bc269d286216382c1f04fb5a015-image.png)

### 解题思路
感谢大佬  [@labuladong](/u/labuladong/) 的讲解!

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
	if (nums == NULL || numsSize == 0) {
	    *returnSize = 0;
	    return NULL;
	}

	int i, index=0, head=0, tail=-1;

	int *res;	//存储各个窗口中最大值的数组
	int *queue; //单端队列，即队列元素递减有序

	*returnSize = (numsSize - k + 1);
	res = malloc(sizeof(int) * (*returnSize));

	queue = malloc(sizeof(int) * numsSize);
	memset(queue, 0, sizeof(int) * numsSize);//初始化队列中元素为0

	for (i = 0; i < numsSize; i ++) {
		//若队列不为空，且当前的值要比队尾的值要小，则压死较小者~
	    while (head <= tail && nums[i] > nums[queue[tail]]) {
	        tail --;
	    }
	    queue[ ++ tail] = i; //入队，记录其下标值
	    if (i - index + 1 == k) {//当窗口开始移动了
	        res[index ++] = nums[queue[head]];//存入最大值
	    }
	    // 当窗口不再含有 当前队列中的最大元素时，则需要出队
	    while (head <= tail && i - queue[head] + 1 >= k) {
	        head ++;
	    }
	}

	free(queue);
	return res;
}
```