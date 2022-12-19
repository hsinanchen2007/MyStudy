### 解题思路
从后往前排。从后向前遍历， 如果A大，A的索引指向前一个。同理B

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int index = ASize - 1;
    while (m && n) {
        if (A[m - 1] < B[n - 1]) {
            A[index] = B[n - 1];
            n--;
        } else {
            A[index] = A[m - 1];
            m--;
        }
        index--;
    }
    while (m) {
        A[index] = A[m - 1];
        m--;
        index--;
    }
    while (n) {
        A[index] = B[n - 1];
        n--;
        index--;
    }
}
```