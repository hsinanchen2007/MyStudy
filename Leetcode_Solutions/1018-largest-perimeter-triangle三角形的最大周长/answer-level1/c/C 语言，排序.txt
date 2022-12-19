### 解题思路
本题采用排序
排序不难，关键在于构成三角形的充要条件的判断
由海伦公式出发，结合任两边之和大于第三边等思路，得到以下等价条件: 

三角形成立且面积 > 0 <<--->> S = sqrt(p(p - a)(p - b)(p - c)) 存在 且 > 0, p = (a + b + c) / 2
<<--->> p > a && p > b && p > c

T: O(NLOG)
s: O(1)

---

总而言之，任两边之和大于第三边 等价于 短边之和 大于 长边

当然，也可以冒泡，在最好情况下 3 次冒泡即可
但是平均下 还是 N2
平均来看，堆排序更优秀

### 代码

```c
void adjustDown (int a[], int k, int n) {
    int temp = a[k - 1];
    for (int i = 2 * k; i <= n; i = 2 * k) {
        if (i + 1 <= n && a[i + 1 - 1] > a[i -1]) ++i;
        if(temp >= a[i - 1]) break;
        a[k - 1] = a[i - 1];
        k = i;
    }
    a[k - 1] = temp;
}

void buildHeap (int a[], int n) {
    for (int i = n / 2; i >= 1; --i) {
        adjustDown(a, i, n);
    }
}

void heapSort (int a[], int n) {
    buildHeap(a, n);
    for (int i = n - 1; i >= 1; --i) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjustDown(a, 1, i);
    }
}

// 三角形成立且面积 > 0 <<--->> S = sqrt(p(p - a)(p - b)(p - c)) 存在 且 > 0, p = (a + b + c) / 2
int largestPerimeter(int* A, int ASize){
    heapSort(A, ASize);
    int i = ASize - 1;
    int j = ASize - 2;
    int k = ASize - 3;
    int a = A[i];
    int b = A[j];
    int c = A[k];

    while (k >= 0) {
        a = A[i];
        b = A[j];
        c = A[k];
        int p = a + b + c;
        if ((p > 2 * c) && (p > 2 * b) && (p > 2 * a)) break;

        // 显然
        // p > 2 * c
        // p > 2 * b

        // 必然此种失败情形 p <= 2 * a
        i = j;
        j = k;
        k = k - 1;
    }

    return k < 0? 0: a + b + c;
}
```