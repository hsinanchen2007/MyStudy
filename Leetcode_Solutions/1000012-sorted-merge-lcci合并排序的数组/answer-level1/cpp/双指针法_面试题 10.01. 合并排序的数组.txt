### 解题思路一 简单排序法 O(nlogn)
    /*
     * 方法1 简单排序法 O(nlogn)
     *
     * 将数组B添加到数组A后，使用std::sort()函数对整个数组A排序
     * 由sort函数的简单排序，时间复杂度最快为O(nlogn)
     * */
### 代码

```cpp
void merge(std::vector<int> &A, int m, std::vector<int> &B, int n) {
    for (int i = m; i < m + n; i++) {
        A[i] = B[i - m];
    }

    std::sort(A.begin(), A.end());
}
```

### 解题思路二 双指针法 O(n)
    /*
     * 方法2 双指针法 O(n)
     *
     * 因为数组A和B都是有序的，那么对他们的比较就可以使用指针处理，
     * 设置数组C存储排序后的数组，再设置两个指针pa,pb分别指向数组A,B，
     * 比较两指针指向的数值，将较小的存储在数组C的前面，指针右移
     * */
### 代码

```cpp
void merge(std::vector<int> &A, int m, std::vector<int> &B, int n) {
    std::vector<int> C;
    int pa = 0, pb = 0;
    while (pa < m && pb < n) {
        if (A[pa] < B[pb]) {
            C.push_back(A[pa]);
            pa++;
        } else {
            C.push_back(B[pb]);
            pb++;
        }
    }

    while (pa >= m && pb < n) {
        C.push_back(B[pb]);
        pb++;
    }

    while (pa < m && pb >= n) {
        C.push_back(A[pa]);
        pa++;
    }

    A = C;
}
```

### 解题思路一 逆双子针法 O(n)
    /*
     * 方法3 逆向双指针法 O(n)
     *
     * 与方法2类似，因为数组A事先设置了数组B的空间（自己设置也可，道理相同）
     * 可以从两数组的最大数值开始，使用两指针比较，将较大的数值放在A数组的末尾，
     * 这样做的好处是能比方法2减少空间复杂度，为O(1)
     * */
### 代码

```cpp
void merge(std::vector<int> &A, int m, std::vector<int> &B, int n) {
    int pa = m - 1, pb = n - 1, cur = m + n - 1;
    while (pa >= 0 && pb >= 0) {
        if (A[pa] > B[pb]) {
            A[cur] = A[pa];
            pa--;
            cur--;
        } else {
            A[cur] = B[pb];
            pb--;
            cur--;
        }
    }

    while (pb > -1) {
        A[pb] = B[pb];
        pb--;
    }
}
```