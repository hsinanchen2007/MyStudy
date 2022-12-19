### 解题思路
倒序遍历A，B中有效元素，直到将B中元素全部填入A中。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        while(n) A[m+n] = (m > 0 && A[m-1] > B[n-1])?A[--m]:B[--n];
    }
};
```