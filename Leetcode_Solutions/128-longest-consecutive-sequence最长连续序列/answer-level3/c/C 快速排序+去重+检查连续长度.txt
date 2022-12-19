### 解题思路
1、针对传入数组nums进行快速排序
2、将排序后的数组去重
3、针对唯一递增的数组，查找最大连续长度的序列
![image.png](https://pic.leetcode-cn.com/e3b566a20dc285b4e0eb89a35cfc5a955d30b9556d5522a05bbbb5bffdb7a52e-image.png)


### 代码

```c
// 针对超大型负数相减越界问题，利用大于号&&小于号实现快速排序
int cmp(const void* a, const void* b)
{
    return (*(int*)a > *(int*)b) ? 1 : -1;
}

int longestConsecutive(int* nums, int numsSize){
	if (!nums || numsSize == 0) // 空数组
		return 0;

	int *sort = (int *)malloc(sizeof(int) * numsSize);
    int *remove_dup = (int *)malloc(sizeof(int) * numsSize);
    // 如果输入用例包含remove_dup的默认值，则计算remove_dup的长度会建议，所以把初始值设置成一个不常用的值
    memset(remove_dup, 10086, numsSize * sizeof(int));  
	int max_con = 1;        // 默认最大值为1
	int cons = 1;

    for (int i = 0; i < numsSize; i++) {
        sort[i] = nums[i];
    }

    qsort(sort, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        printf("%d, ", sort[i]);
    }
    printf("\n");

    int remove_dup_size = numsSize;
    int j = 0;
    int index = 0;
    // 去除快速排序后的重复元素
    while (index < remove_dup_size) {
        // 需要再加一条判断，用于排除sort[j] == remove_dup默认值的场景，后续再添加
        if (remove_dup[index] == sort[j]) {
            remove_dup_size--;
        } else {
            remove_dup[index++] = sort[j];
        }
        j++;
    }
    for (int i = 0; i < remove_dup_size; i++) {
        printf("%d, ", remove_dup[i]);
    }
    printf("\n");

	for (int i = 1; i < numsSize; i++) {
		if (remove_dup[i] == remove_dup[i - 1] + 1)	{	// Consecutive Sequence
			cons++;
			if (cons > max_con)
				max_con = cons;
		} else {
			cons = 1;
		}
	}
    free(sort);
    free(remove_dup);
	return max_con;
}
```