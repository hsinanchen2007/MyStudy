### 解题思路
依次比较A和B的最大值，如果到最后B还未放完，直接复制到A里

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = m - 1;
    int j = n - 1;
    int idx = n + m - 1;

    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[idx--] = A[i--];

        } else {
            A[idx--] = B[j--];
        }
    }

    if (j >= 0) {
        for (int k = 0; k <= j; k++) {
            A[k] = B[k];
        }
    }

}
```