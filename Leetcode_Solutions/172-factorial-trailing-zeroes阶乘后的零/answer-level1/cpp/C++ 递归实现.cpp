找因子5的道理就不解释了，下面是递归实现方法：

```
class Solution {
public:
    int trailingZeroes(int n) {
        
        if (n/5==0) {return 0;}
        else {return (n/5 + trailingZeroes(n/5));}
        
    }
};
```

![image.png](https://pic.leetcode-cn.com/08c3ae75cbfd85f92b8911ee60521056de6e174245a7c654733c3d58e7cf3c2a-image.png)
