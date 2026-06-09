假设f(n)为n个快递有效序列的解，那么易得f(1) = 1;
我们可以把这个问题看成是一个简单的排列问题，已知f(n) = n，那么在此基础上多增加一个快递会怎样呢？
当有n个快递的时候，序列里有2n个元素，那么多增加一个快递，其实就是将两个元素插入到2n个元素的序列当中，显然插入的情况是(2n+1)×(2n+2)，由对称性可以知道，其中一半是P1在D1之前，一半是P1在D1之后。所以有效情况就是(2n+1)×(2n+2)/2。
所以f(n+1) = f(n) × (2n+1)×(2n+2)/2。
```
class Solution {
    public int countOrders(int n) {
        if (n == 1) return 1;
        else {
            int sum = (2*n-1)*(2*n)/2;
            return (int)(((long)sum * (long)countOrders(n-1)) % 1000000007);
        }
    }
}
```

![图片.png](https://pic.leetcode-cn.com/a2229c48b5e814828f30163887234ebd0fa8553bc84c06cfcb89ecb7f5848404-%E5%9B%BE%E7%89%87.png)
