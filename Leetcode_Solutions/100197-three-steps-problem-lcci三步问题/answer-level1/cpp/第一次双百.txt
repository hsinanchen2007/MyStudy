### 解题思路
很简单，没有什么说的

### 代码

```cpp
class Solution {
public:
    int waysToStep(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        long int c1 = 1,c2 = 1, c3 = 2;
        for(int i = 3;i<=n;i++ )
        {
           long int c0 = (c1+c2+c3)%1000000007;
            c1 = c2;
            c2 = c3;
            c3 = c0;
        }
        return c3;

    }
};
```