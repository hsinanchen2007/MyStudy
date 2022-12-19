### 解题思路
约瑟夫数学问题：每删除一个数，其实就是把这个数组向前移动了M位。然后逆过来，就可以得到这个递推式。
f(n,m)=(f(n-1,m) + m) % n;

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int p = 0;
        for(int i=2; i<=n; i++)
        {
            p=(p + m) % i;
        }
        return ans;
    }
};
```