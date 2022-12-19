解题思路：
1、备份数组；
2、对备份数组进行快排，从小到大；
3、从最大到最小搜寻元素(下标flag)在原始数组中的索引index，交换0~index 之间所有元素的位置，记录index;
4、交换0~flag之间所有元素，记录flag；
5、按照3 & 4步骤全部遍历，最后获取结果；

示例代码如下：
```
static int ComFun(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

static int FindIndex(const int *array, int size, int value)
{
    int i;

    for (i = 0; i < size; i++) {
        if (array[i] == value)
            return i + 1;
    }
    return -1;
}

void SwapArray(int *array, int size)
{
    int i = 0;
    int tmp;

    for (i = 0; i < size/2; i++) {
        tmp = array[i];
        array[i] = array[size - 1 -i];
        array[size - 1 -i] = tmp;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int* A, int ASize, int* returnSize){
    int *tmp = (int *)malloc(sizeof(int) * ASize);
    int *result = (int *)malloc(sizeof(int) * ASize * 2);
    int flag = ASize - 1;
    int cnt = 0;
    int index;

    memcpy(tmp, A, sizeof(int)*ASize);
    (void)qsort(tmp, ASize, sizeof(int), ComFun);

    while(flag > 0) {
        index = FindIndex(A, flag + 1, tmp[flag]);
        if (index != -1 && flag != index - 1) {
            if (index != 1)
                result[cnt++] = index;
            SwapArray(A, index);
            result[cnt++] = flag + 1;
            SwapArray(A, flag + 1);
        }
        flag--;
    }
    *returnSize = cnt;
    return result;
}
```
