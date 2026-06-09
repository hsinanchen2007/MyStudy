### 解题思路
已知一半奇数，一半偶数，排奇数，或者排偶数，皆可，排好一半，剩下自然有序
双指针法，以下算法排的是奇数序列

i --> 偶数位置
j --> 奇数位置
偶数位上的奇数，与奇数序列的异常位置（奇数位上的偶数）进行交换
j 始终指向奇数有序序列的下一个（即，保证 j 之前的奇数有序）
如此即可

T: O(N)
S: O(N)

存储实际上 O(1), 题目要求 malloc 新的，不然原数组操作即可

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int *res = (int *)malloc(ASize * sizeof(int));
    returnSize[0] = ASize;

    for (int i = 0, j = 1; i < ASize && j < ASize; i += 2) {
        if (A[i] % 2) {// 偶数位上的奇数
            while (j < ASize && A[j] % 2) j += 2;// 找到奇数序列的最近异常点(奇数位上的偶数)
            if (j < ASize) {// 异常点处理，使奇数序列有序
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                j += 2;
            }
        }
    }

    // 拷贝，题意要求新数组，那就简单拷贝，懒得优化
    for (int i = 0; i < ASize; ++i) res[i] = A[i];

    return res;
}
```