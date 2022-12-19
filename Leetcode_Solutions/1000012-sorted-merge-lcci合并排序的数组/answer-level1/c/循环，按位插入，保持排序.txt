### 解题思路
1. 设置有效数字总数total；
2. 每次拿B中最后一位数字（最大值）与A原本的末尾数对比，将较大数插在total-1处，对应的待排数字m或n自减；
3. 直到n=0时结束，得到合并序列。

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int total = m + n;

    while (n > 0) {
        while (m > 0 && B[n - 1] <= A[m - 1]) {
            A[total - 1] = A[m - 1];
            total--;
            m--;
        }
        A[total - 1] = B[n - 1];
        total--;
        n--;
    }
}
```