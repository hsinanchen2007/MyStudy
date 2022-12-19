### 解题思路


### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int len_A = m + n - 1;  //A的最后一个元素坐标
        int i = m-1, j = n-1;  
        while(i >= 0 && j >= 0){  //双指针,从后向前
            A[len_A--] = (A[i] < B[j] ? B[j--] : A[i--]);
        }
        while(j >= 0) A[len_A--] = B[j--];  //当B的有效长度比A的长时，最后就直接归入即可
    }
};
```