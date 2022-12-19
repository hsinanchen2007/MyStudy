# 方法一：首尾双指针

```c++ []
vector<int> sortArrayByParityII(vector<int>& A) {
    int i = 0, j = A.size() - 1;
    while (i<A.size()&& j>0) {
        if (!(A[i] % 2)) { i += 2; continue; }
        if (A[j] % 2) { j -= 2; continue; }
        A[i] ^= A[j];
        A[j] ^= A[i];
        A[i] ^= A[j];
        i += 2;
        j -= 2;
    }
    return A;
}
```

# 方法二：首部双指针

```c++ []
vector<int> sortArrayByParityII(vector<int>& A) {
    for (int i = 0, j = 1; i < A.size(); i += 2) {
        if (A[i] % 2) {
            while (A[j] % 2) j += 2;
            A[i] ^= A[j];
            A[j] ^= A[i];
            A[i] ^= A[j];
        }
    }
    return A;
}
```

两种双指针思想是一样的，看大家习惯喽~

