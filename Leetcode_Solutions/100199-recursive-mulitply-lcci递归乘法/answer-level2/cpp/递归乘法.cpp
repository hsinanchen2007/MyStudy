### 解题思路

### 代码

```cpp
class Solution
{
public:
    typedef long long ll;

    int multiply(int A,int B) 
    {
        if(A>B) swap(A,B);
        return M(A,B);
    }

    int M(int A,int B)
    {
        if(A==1) return B;
        return M(A-1,B)+B;
    }
};
```