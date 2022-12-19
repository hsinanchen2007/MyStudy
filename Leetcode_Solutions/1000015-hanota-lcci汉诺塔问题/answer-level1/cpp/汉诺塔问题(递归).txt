### 解题思路

### 代码

```cpp
class Solution 
{
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) 
    {
        move(A.size(),A,B,C);
    }

    void move(int n,vector<int>& A,vector<int>& B,vector<int>& C)
    {
        if(n-1) move(n-1,A,C,B);

        C.push_back(A.back());
        A.pop_back();

        if(n-1) move(n-1,B,A,C);
    }
};
```