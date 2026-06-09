### 解题思路
见代码，注意要把原来的A序列另存起来，防止干扰

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> origin;
        for ( int elt : A ) {
            origin.push_back(elt);
        }                                                   // 把原来的A复制过去
        int i = 0, j = 0, k = 0;
        while ( i < m && j < n ) {                          // 归并排序
            if ( origin[i] < B[j] ) {                           // 将较小的依次放入A[k++]
                A[k++] = origin[i++];
            } else {
                A[k++] = B[j++];
            }
        }

        while ( i < m ) {
            A[k++] = origin[i++];
        }
        while ( j < n ) {
            A[k++] = B[j++];
        }
    }
};
```