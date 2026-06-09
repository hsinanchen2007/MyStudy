### 解题思路
![...题 10.01. 合并排序的数组.mp4](db33f3f6-b537-47a6-b7c4-0fa56a45f306)


### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int p = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0){
            A[i] <= B[j] ? A[p--] = B[j--] : A[p--] = A[i--];
        }
        while(j >= 0){
            A[p--] = B[j--];
        }
    }
};
```