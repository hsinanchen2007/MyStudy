### 解题思路
新建一个数组，将A和B数组中的数字一个一个插入进去，由于A、B都是以排序的数组，所以设两个记录A、B两个数组已排序的位置，只需要比较当前位置的数字的大小，然后插入就可以，最后将排序好的数组重新赋给A就可以了

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    // 排序过的数组
    int sorted[m + n];

    // 记录A、B两个数组已排序过的位置
    // 相当于指针的作用
    int pa, pb, cur;
    pa = 0;
    pb = 0;

    while (pa < m && pb < n) {
        if (A[pa] < B[pb]) {
            cur = A[pa];
            pa += 1;
        } else {
            cur = B[pb];
            pb += 1;
        }
        
        sorted[pa + pb - 1] = cur;
    }

    while (pa < m) {
        sorted[pa + pb] = A[pa];
        pa += 1;
    }

    while (pb < n) {
        sorted[pa + pb] = B[pb];
        pb += 1;
    }

    for (cur=0; cur<m+n; cur++) {
        A[cur] = sorted[cur];
    }
}
```