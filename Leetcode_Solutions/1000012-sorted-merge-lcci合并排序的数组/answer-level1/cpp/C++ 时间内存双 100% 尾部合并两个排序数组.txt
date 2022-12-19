### 解题思路
本题需要我们在 $A$ 的基础上，将 $B$ 合并入 $A$ 并保持升序
由于空余空间在 $A$ 的尾部，如果从头部开始存放，会导致数组元素后移或者其他额外的操作。
所以我们从尾部空余空间入手，从 $A$ 和 $B$ 的尾部 $(m-1,n-1位置)$ 开始，依次将较大的数组放入 $A$ 的尾部 $(m+n-1位置)$，从而不产生额外的空间，一轮遍历结束

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int cur = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0){
            if(A[i] > B[j]){
                A[cur] = A[i];
                i--;
                cur--;
            }
            else{
                A[cur] = B[j];
                j--;
                cur--;
            }
        }
        while(i >= 0){
            A[cur] = A[i];
            cur--;
            i--;
        }
        while(j >= 0){
            A[cur] = B[j];
            cur--;
            j--;
        }
    
    }
};
```