### 解题思路
一开始用队列模拟，复杂度O(nm)，T掉了，一看数据范围，只能上递推式了
f(n,m)=(f(n-1,m)+m)%n
![image.png](https://pic.leetcode-cn.com/9654a768fe1f159e7f0ba1644b6d18b5f1693a654bb6306f71e31e3ed20d0c33-image.png)


### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans=0;
        for(int i=2;i<=n;++i) ans=(ans+m)%i;
        return ans;
    }
};
```