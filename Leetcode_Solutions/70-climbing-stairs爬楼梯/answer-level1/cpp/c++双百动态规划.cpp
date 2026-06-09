### 解题思路
典型的斐波那契数列，不需要定义整个数组，用三个参数滚动存储即可

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int a1=1,a2=2;
        if(n<3)return n;
        for(int i=3;i<=n;i++)
        {
            int a=a1+a2;
            a1=a2;
            a2=a;
        }
        return a2;
    }
};
```