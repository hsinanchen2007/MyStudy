### 解题思路
1.因为奇偶各占一半，所以可以很容易知道数组最后一个元素的下标（ASize - 1）一定是奇数
2.从数组头开始（A[0]）往后下标加2，对应的值应该为偶数，同理，从数组尾开始（A[ASize - 1]）往前减2，对应的值应该为奇数
3.找到不合符要求的偶数下标和奇数下标，互换对应的值，以此类推，直到下标不在有效范围结束（可以很明确的知道，不符合要求的奇数和偶数一定相等）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    if (A == NULL || returnSize == NULL) {
        return NULL;
    }

    int i = 0;          // 偶数下标
    int j = ASize - 1;  // 奇数下标
    while (i < ASize && j > 0) {
        while (i < ASize && A[i] % 2 == 0) { // 找到偶数下标但值为奇数的数
            i += 2;
        }
        if (i >= ASize) {
            break;
        }

        while (j > 0 && A[j] % 2 != 0) { // 找奇数下标但值为偶数的数
            j -= 2;
        }
        if (j <= 0) {
            break;
        }

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    *returnSize = ASize;
    return A;
}
```