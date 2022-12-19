### 解题思路
此处撰写解题思路
![c.png](https://pic.leetcode-cn.com/75ed31ba84a35875d222c7fbe326e24133e147f4d335109837c17fa20220669a-c.png)



### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArr(int* a, int aSize, int* returnSize){
    int *arr = NULL;
    int i, temp;
    if (a == NULL || aSize <= 1) {
        *returnSize = 0;
        return a;
    }
    *returnSize = aSize;
    arr = (int *)malloc(sizeof(int) * aSize);
    arr[0] = 1;

    for (i = 1; i < aSize; i++) {
        arr[i] = arr[i - 1] * a[i - 1];
    }

    temp = 1;
    for (i = aSize - 2; i >= 0; i--) {
        temp *= a[i + 1];
        arr[i] *= temp;
    }

    return arr;
}
```