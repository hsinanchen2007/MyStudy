### 解题思路
可以采用不带哨兵和带哨兵的两种解题方式

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        // O(m+n)
        // 2020 3 24 9：47
        // 不带哨兵
        /*
        int A_cur = 0;int B_cur = 0;
        int cur = 0;
        vector<int> temp = A;
        while(A_cur < m && B_cur < n){
            A[cur++] = temp[A_cur] > B[B_cur] ? B[B_cur++] : temp[A_cur++]; // 将较小的元素插入
        }
        if(A_cur == m){
            while(B_cur < n) A[cur++] = B[B_cur++];
        }//
        else if(B_cur == n){
            while(A_cur < m) A[cur++] = temp[A_cur++];
        }
        */
        // 带哨兵
        int A_cur = 0; int B_cur = 0;
        int cur = 0;
        if(n != 0){
            vector<int> temp = A;
            temp[m] = INT_MAX; 
            B.push_back(INT_MAX); // 哨兵
            int tag = m+n;
            while(cur < tag){
                A[cur++] = temp[A_cur] > B[B_cur] ? B[B_cur++] : temp[A_cur++]; // 将较小的元素插入
            }
        }
    }
};
```