### 解题思路

![image.png](https://pic.leetcode-cn.com/aa0c0e199873937fe33ef567cd990889eb4ddb501952d946c71e1c4d0fb54ea7-image.png)


### 代码

```c
void removeElement(int *array, int index, int size) {
    if (index >= size || index < 0) {
        printf("index of range \n");
        return;
    }

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i+1];
    }
    return;
}

int calSize(int size) {
    int ret = 1;
    for (int i = 1; i < size; i++) {
        ret *= i;
    }
    return ret;
}

void insertElement(int *array, int index, int size, int element) {
    if (index >= size || index < 0) {
        printf("index of range \n");
        return;
    }

    for (int i = size - 1; i > index; i--) {
        array[i] = array[i-1];
    }
    array[index] = element;
    return;
}

void DFS(int* a, int index, int size, int **ret, int* rS, int* rCS) {
    // termination
    if (size == 0) {
        *rS += 1;
        return;
    }

    if (size < 0) {
        printf("error\n");
    }

    // process
    int element = a[index];
    int curSize = calSize(size);
    for (int i = 0; i < curSize; i++) {
        ret[*rS + i][rCS[*rS + i]] = element;
        rCS[*rS + i] += 1;
    }
    // printf("%d\n", element);
    removeElement(a, index, size);
    size--;
    if (size == 0) {
        *rS += 1;
    }
    for (int i = 0; i < size; i++) {
        DFS(a, i, size, ret, rS, rCS);
    }
    // drill down

    // clear up
    size++;
    insertElement(a, index, size, element);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize <= 0) {
        return NULL;
    }
    int spaceSize = calSize(numsSize + 1);

    int **ret = (int **)calloc(spaceSize, sizeof(int *));
    int *rCS = (int *)calloc(spaceSize, sizeof(int));
    for (int i = 0; i < spaceSize; i++) {
        ret[i] = (int *)calloc(numsSize, sizeof(int));
    }

    for (int i = 0; i < numsSize; i++) {
        DFS(nums, i, numsSize, ret, returnSize, rCS);
    }

    *returnColumnSizes = rCS;
    return ret;
}
```