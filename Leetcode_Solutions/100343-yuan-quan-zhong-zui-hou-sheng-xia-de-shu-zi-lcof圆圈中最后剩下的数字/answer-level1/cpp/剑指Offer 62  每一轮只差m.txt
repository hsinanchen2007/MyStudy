![image.png](https://pic.leetcode-cn.com/f6b0c7f125efa281b3e87ff61d042f168d4d4dfd80269256996209fc57ca0f1c-image.png)

### 解题思路
![image.png](https://pic.leetcode-cn.com/8c8d12c427a322f0c61fe7391bf92d1faf3c5f042828badc81a651cc8fd86624-image.png)

看了好多题解都没懂。。感谢这位大佬。[@jerryqiang](/u/jerryqiang/)
### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n == 1) return 0;
        int res = 0;             // f(1,m) = 0
        for(int i=2; i<=n; i++){ // 依次计算f(2,m), f(3,m), f(4,m),,,一直到f(n,m)
            res = (res + m)%i;
        }
        return res;
    }
};
```
真的牛逼