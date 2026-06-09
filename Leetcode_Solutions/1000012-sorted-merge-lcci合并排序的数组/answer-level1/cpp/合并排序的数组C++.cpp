### 解题思路
A,B只访问一遍，
执行用时 :4 ms, 在所有 C++ 提交中击败了78.97%的用户
内存消耗 :11.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int insert_idx = 0;
        int i, j;
        for(i = 0; i < n; ++i){     //准备向A中插入B[i]
            for(j = insert_idx; j < m; ++j){
                if(B[i] < A[j]){       //插入位置为j
                    for(int k = m; k > j; k--){  //在A中腾出B[i]的位置
                        A[k] = A[k-1];
                    }
                    A[j] = B[i];
                    insert_idx = j + 1;
                    m++;
                    break;
                }
            }
            if(j == m) break;
        }
        for(int p = i; p < n; p++){
            A[j] = B[p];
            ++j; 
        }
    }
};
```