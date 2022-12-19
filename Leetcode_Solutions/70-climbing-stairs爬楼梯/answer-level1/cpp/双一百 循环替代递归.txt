### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
       int result[3] = {0,1,2};
       if(n <= 2)
       return result[n];
       long long  a = 2;
       long long  b = 1;
       long long  m = 0;
       for(int i = 3; i <= n; ++i)
       {
           m = a+b;
           b = a;
           a = m;
       }
        return m;
        
        
    }
};
```