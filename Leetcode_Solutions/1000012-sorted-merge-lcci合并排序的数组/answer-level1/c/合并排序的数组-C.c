### 解题思路
此处撰写解题思路
1.申请数组。
2.比较两个数组，放入到申请的数组中。
3.考虑边界：原数组全为0，
### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i, j, k;
    int *p;
    int flag = 0;

    if (ASize < BSize || ASize == 0) {
        return;
    }

    for (i = 0; i < m; i++) {
        if (A[i] == 0) {
            flag++;
        }
    }

    if (flag == m) {
        for(i = 0; i < BSize; i++) {
            A[i] = B[i];
        }
        return;
    }
    if (BSize == 0) {
        return A;
    }
    p = (int *)malloc(sizeof(int) * ASize);
    for (i = 0, j = 0, k = 0; i < ASize; i++) {
        printf("A[%d]=%d,B[%d]=%d\n", j, A[j], k, B[k]);
        if (A[j] < B[k]) {
            p[i] = A[j];
            j++;
            printf("p[%d]=%d\n", i, p[i]);
        } else {
            p[i] = B[k];
            k++;
            printf("p[%d]=%d\n", i, p[i]);
        }
        printf("i=%d, j=%d, k=%d\n", i, j, k);
        if (k == n) {
            break;
        } else if (j == m) {
            break;
        }
    }
    if (k == n) {
        for (i++; i < ASize; i++) {
            p[i] = A[j];
            printf("p[%d]=%d,A[%d]=%d\n", i, p[i], j, A[j]);
            j++;
        }
    } else if (j == m) {
        for (i++; i < ASize; i++) {
            p[i] = B[k];
            printf("p[%d]=%d,B[%d]=%d\n", i, p[i], k, B[k]);
            k++;
        }
    }
    for (i = 0; i < ASize; i++) {
        A[i] = p[i];
    }
    free(p);
    p = NULL;

    return;
}
```