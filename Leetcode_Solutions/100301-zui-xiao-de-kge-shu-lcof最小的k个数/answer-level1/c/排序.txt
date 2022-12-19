### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/9456773bab0c8d58d949bb32d2afee6e66d60cd1420b28473d381f2dbe6f1659-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    long n1 = *(int*)a;
    long n2 = *(int*)b;

    return n1 - n2;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = k;

    int *res = calloc(k, sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = arr[i];
    }

    return res;
}
```