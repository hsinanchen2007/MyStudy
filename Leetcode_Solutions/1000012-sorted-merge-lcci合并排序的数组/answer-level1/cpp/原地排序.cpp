### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :11.5 MB, 在所有 C++ 提交中击败了100.00%的用户

两个有序数组合并，使用归并操作。为了方便，取两个数组的尾数，谁大谁就放到最后，对应数组的尾数删除，直到B的所有数都插入到A当中结束。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
       if(m==0){A.swap(B);}
       else{
       while(n>0&&m>0){
        if(A[m-1]<=B[n-1]){
             A[m+n-1]=B[n-1];
            n--;}
        else{
             A[m+n-1]=A[m-1];
            m--;}
        }
        if(m==0){
            for(int i=0;i<n;i++){
                A[i]=B[i];
            }
        }
       }
    }
};
```