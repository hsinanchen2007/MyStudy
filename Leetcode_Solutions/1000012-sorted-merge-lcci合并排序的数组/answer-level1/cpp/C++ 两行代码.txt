
```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int last = m + n - 1, apos = m - 1, bpos = n - 1;
        while (last != -1) apos != -1 && (bpos == -1 || A[apos] > B[bpos]) ? A[last--] = A[apos--] : A[last--] = B[bpos--];
    }
};
```

别问，问就是可读性不好！

上面代码是从下面这种简化而来的。


### 思路

- 从后往前遍历
- $last$ 指针 指向 $A$ 中的插入位置
- $apos$ 和 $bpos$ 两个指针分别从 $A$ 数组末尾和 $B$ 数组末尾
- 每次将 $A[apos]$ 和 $B[bpos]$ 中较大的插入到 $last$ 位置即可

感谢 [@liweiwei1419](/u/liweiwei1419/) 对代码的可读性提出了建议。

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int last = m + n - 1;
        int apos = m - 1;
        int bpos = n - 1;
        while (apos != -1 && bpos != -1) {
            if (A[apos] > B[bpos]) {
                A[last] = A[apos];
                apos--;
            } else {
                A[last] = B[bpos];
                bpos--;
            }
            last--;
        }
        while (bpos != -1) {
            A[last] = B[bpos];
            last--;
            bpos--;
        }
    }
};
```
