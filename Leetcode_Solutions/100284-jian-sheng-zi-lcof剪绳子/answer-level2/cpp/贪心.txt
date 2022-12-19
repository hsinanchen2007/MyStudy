### 解题思路
![RES.png](https://pic.leetcode-cn.com/cc78fabc11250b7e2042d11d410df91c27a5d271b162406ddf8e0653b6398ebe-RES.png)


### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3)return n-1;
        if(n%3==0)return pow(3,n/3);
        else if(n%3==2)return pow(3,n/3)*2;
        else return pow(3,n/3-1)*4;
    }
};
```