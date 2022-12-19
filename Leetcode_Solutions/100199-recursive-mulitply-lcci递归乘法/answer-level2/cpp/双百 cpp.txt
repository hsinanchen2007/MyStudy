### 解题思路
循环B次  每次加上A

### 代码

```cpp
class Solution {
public:
    int multiply(int A, int B) {
        int res=0;
        while(B--) res+=dfs(A);
        return res;
    }
    inline int dfs(int A)
    {
        return A;
    }
};
```