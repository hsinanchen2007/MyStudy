### 解题思路
从数组A的尾部开始存放，从数组A和数组B的最后一个元素开始遍历，将大的放到数组A的尾部。
特别提醒：如果遍历结束，数组B还有未访问的元素，最后不要忘了将B中剩余的数放到A中

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if((m < 1 && n < 1) || n < 1)
            return;
        int A_i = m - 1, B_i = n - 1, res_i = m + n - 1;               
        while(A_i >= 0 && B_i >= 0){
            if(A[A_i] > B[B_i]){
                A[res_i--] = A[A_i];
                A_i--;
            }
            else{
                A[res_i--] = B[B_i];
                B_i--;
            }
        }
        while(B_i >= 0){
                A[res_i--] = B[B_i];
                B_i--;               
        }
    }
};
```