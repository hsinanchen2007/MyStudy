### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        A.erase(A.begin()+m,A.end());       //A.resize(m)   更简洁;
        for(int n:B)
        A.push_back(n);

        sort(A.begin(),A.end());
    }
};
```