### 解题思路

最开始想到的是同时从后边遍历A的前半部分和B，将较大的值放在B中，最后将B赋值到A的后半部分中
这个方法的时间复杂度为O(m + 2n),可以接受
但是在尝试的过程中发现，当A[i] > B[j]时，将两者交换后，A便不再是一个有序数组

于是想到可以直接将较大的值放在A的最后面
即
同时从后边遍历A的前半部分和B，将较大的值放在A的后面
时间复杂度为O(m + n)

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int idx = m + n - 1, i = m - 1, j = n - 1; idx > i; --idx)
            A[idx] = (i >= 0 && A[i] > B[j]) ? A[i--] : B[j--];
    }
};
```