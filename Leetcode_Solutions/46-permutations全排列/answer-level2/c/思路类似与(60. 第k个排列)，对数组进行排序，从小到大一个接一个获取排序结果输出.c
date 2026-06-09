**思路很简单：**
1. 先按照简单的排列组合原理，计算出所有可能的排列个数，其实就是N!
2. 先将数字按照从小到大排序，生成第一个返回值，比如：输入[1, 4, 2, 3]，则第一个返回就是[1, 2, 3, 4]
3. 从该第一个排列，生成下一个排列，要求是下一个最小的排列，即下一个是：[1, 2, 4, 3]

再说下下一个排列的生成规则，以1、4、2、5、3这样的排列为例，找下一个比它大且最接近他的排列，规则如下：
1. 从后向前，找到后面数字比前面大的，记录位置，容易发现，3比2大，则交换3和2的位置，生成：1、4、3、5、2
2. 交换位置后，就是最解决原始排列的了么？还不是，还需要将3后面的进行从小到大排列，生成：1、4、3、2、5
3. 得解

这个交换位置的这一步，3的位置选择要注意，要选择最低位的，比如1、2、4、5、3这样的排列，不能用3和2替换位置，而是用5和4替换位置，这样才是最接近的。

**附代码：**

```
int _compare_int(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

void getNextArray(int *nums, int numsSize) {
    int heightIdx = -1;
    int lowIdx = -1;
    for (int i = numsSize - 1; i >= 0; --i) {
        //找到高位比低位小的，交换位置，得到一个更大的值
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                //注意，最后选择一个值最小的高位来交换，这样才是最接近的
                if (heightIdx == -1 || j > heightIdx) {
                    heightIdx = j;
                    lowIdx = i;
                }
            }
        }
    }
    if (heightIdx == -1) {
        printf("error\n");
        return;
    }

    //进行高低位值交换
    int temp = nums[lowIdx];
    nums[lowIdx] = nums[heightIdx];
    nums[heightIdx] = temp;

    //对高位后面的值，进行从小到大排序，保证是最小的值
    qsort(&nums[heightIdx + 1], numsSize - heightIdx - 1, sizeof(int), _compare_int);
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (numsSize == 0) {
        return NULL;
    }

    //计算总排列个数，即N!
    int size = 1;
    for (int i = 1; i <= numsSize; i++) {
        size *= i;
    }

    //分配返回值的内存空间
    int **retVal = malloc(sizeof(int *) * size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = numsSize;
        retVal[i] = malloc(sizeof(int) * numsSize);
    }

    //对原数组从小到大排序，得到最小排列
    qsort(nums, numsSize, sizeof(int), _compare_int);
    
    //一个接着一个，获取下一个最接近的排列
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < numsSize; ++j) {
            retVal[i][j] = nums[j];
        }
        getNextArray(nums, numsSize);
    }
    *returnSize = size;
    return retVal;
}
```
