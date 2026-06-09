### 代码

```c

int FindNinA(int* A, int ASize, int n)
{
    for (int i = 0; i < ASize; i++) {
        if (A[i] == n) {
            return i;
        }
    }
    return 0;
}

//翻转前n个
void Flip(int* A, int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = A[i];
        A[i] = A[n - 1 - i];
        A[n - 1 - i] = temp;
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int* A, int ASize, int* returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * 10 * ASize);
    int retSize = 0;

    int index;
    for (int i = ASize; i > 0; i--) { //[1, 4]
        index = FindNinA(A, ASize, i);
       // printf("%d: %d\n", i, index);
        if (index == i - 1) {
            continue;
        } else {
            Flip(A, index + 1);
            ret[retSize] = index + 1;
            retSize++;
            Flip(A, i);
            ret[retSize] = i;
            retSize++;
        }
    }


    *returnSize = retSize;
    return ret;
}
```