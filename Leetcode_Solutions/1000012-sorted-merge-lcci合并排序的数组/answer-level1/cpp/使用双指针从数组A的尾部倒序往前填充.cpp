### 解题思路
使用双指针从数组A的尾部倒序往前填充，「就地」算法

该题与 [LeetCode-88题](https://leetcode-cn.com/problems/merge-sorted-array/) 完全相同，可作为参考

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1, cur = m + n - 1;

        while ( i > -1 && j > -1 ) {
            if ( A[i] <= B[j] ) {
                A[cur--] = B[j--];
            }
            else 
                A[cur--] = A[i--];                
        }
        // 如果 i > -1, j = -1，无需对其有任何操作，因为此时数据A已经有序了。
        if ( j > -1 )  
            while ( j > -1 )
                A[cur--] = B[j--];
    }
};
```