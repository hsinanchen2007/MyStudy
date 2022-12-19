### 解题思路
使用内置的排序函数实现；

### 代码

```cpp
class Solution {
public:
    static bool cmp(const int &a,const int &b) {
        return a < b;
    }
    vector<int> sortedSquares(vector<int>& A) {
        for(int i = 0;i < A.size();i++){
            A[i] = A[i]*A[i];
        }
        sort(A.begin(),A.end(),cmp);//内置的排序函数
        return A;
    }
};
```