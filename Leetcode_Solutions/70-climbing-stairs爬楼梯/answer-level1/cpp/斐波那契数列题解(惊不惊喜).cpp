### 解题思路
C++党必做题
此题==斐波那契数列
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int f[100005];
        f[0]=0;f[1]=1;f[2]=2;//初值，切记f[0]=0;
        for(int i=3;i<=n;i++)
            f[i]=f[i-1]+f[i-2];//斐波那契数列公式
        return f[n];
    }
};//本蒟蒻第一次题解，大佬勿喷
```