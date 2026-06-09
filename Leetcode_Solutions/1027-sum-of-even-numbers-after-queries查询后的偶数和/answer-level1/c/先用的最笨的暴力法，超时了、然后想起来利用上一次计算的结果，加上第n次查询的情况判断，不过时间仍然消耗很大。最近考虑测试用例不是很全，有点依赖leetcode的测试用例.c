### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int calSum(int *A, int ASize)
{
    int num = 0;

    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            num += A[i];
        }
    }

    return num;
}

void print(int *A, int ASize) 
{
    for (int i = 0; i < ASize; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int *res = calloc(queriesSize, sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int val = queries[i][0];
        int index = queries[i][1];
    
        if (i == 0) {
            A[index] += val;
            res[i] = calSum(A, ASize);
        }
        else {
            //printf("%d, %d\n", res[i-1], val);
            if (A[index] % 2 == 0) {
                if(val % 2 == 0) {
                    res[i] = res[i-1] + val;
                }
                else {
                    res[i] = res[i-1] - A[index];
                }
            }
            else {
                if (val % 2) {
                    res[i] = res[i-1] + val + A[index];
                }
                else {
                    res[i] = res[i-1];
                }
            }
            A[index] += val;
        }
        //print(A, ASize);
    }

    return res;
}
```