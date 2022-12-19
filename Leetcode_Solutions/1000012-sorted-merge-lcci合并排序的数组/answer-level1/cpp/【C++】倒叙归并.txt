### 解题思路
倒叙归并排序。
分别设置指针i,j从A的m处与B的n处倒序遍历，同时设置一个指针end从A的结尾处倒序遍历，
对A的前m个元素与B的元素倒叙归归并把结果倒序放到A中。

###结果：
*执行用时 :
4 ms, 在所有 C++ 提交中击败了78.97%的用户
内存消耗 :
11.5 MB, 在所有 C++ 提交中击败了100.00%的用户*

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i{m-1};
        int j{n-1};
        int end{A.size()-1};
        while(i >= 0 && j >= 0){
            if(A[i] < B[j]){
                A[end] = B[j];
                j--;
            }else{
                A[end] = A[i];
                i--;
            }
            end -- ;
        }
        while(end != -1 && i == -1){
            A[end] = B[end];
            end --;
        }
    }
};
```