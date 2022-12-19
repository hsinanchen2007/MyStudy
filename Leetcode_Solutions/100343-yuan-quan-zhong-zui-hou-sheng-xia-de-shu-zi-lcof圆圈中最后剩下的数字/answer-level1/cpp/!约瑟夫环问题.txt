### 解题思路
公元1世纪数学家的问题。。。略难;
使用递推公式，f(n)=[f(n-1)+m]%n-1;
具体思路见本题题解.

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int re=0;
        for (int i=2; i<=n; i++) re=(re+m)%i;//f(n)=[f(n-1)+m]%n-1
        return re;
    }
};
```