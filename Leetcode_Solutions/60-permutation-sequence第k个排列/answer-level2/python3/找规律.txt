## 思路:

这道题有个回溯标签,用回溯算法超时,回溯算法真的可以过吗?

我感觉这道题就是个找规律题目!

直接举例子:

比如`n = 3, k = 3`

我们要由`num = [1, 2, 3]`这三个数组成!

首先我们要确定首位置是什么?我们整体看一下所有数;

1. `"123"`
2. `"132"`
3. `"213"`
4. `"231"`
5. `"312"`
6. `"321"`

我们发现当**首数字确定了,后面和首数字组成数字的个数相等的!**

比如: 首数字为`1`,后面有组成两个数`123`,`132`,可以组成2个数.当首数字为`2`,`3`同样都是.

所有我们要找`k = 3`的数字 ,我们只需要 `3/2` 便可找到首数字什么,

下面依次类推!

其实就是一道找规律题目!

代码大同小异, 逻辑都是一样的! 大家可以自己动手写,如有更好的写法分享一下!哈哈!

## 代码:


```python [1]
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        num = [str(i) for i in range(1, n+1)]
        res = ""
        n -= 1
        while n > -1:
            t = math.factorial(n)
            loc = math.ceil(k / t) - 1
            res += num[loc]
            num.pop(loc)
            k %= t
            n -= 1
        return res
```



```java [1]
class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> num = new ArrayList<>();
        for (int i = 1; i <= n; i++) num.add(i);
        int[] factorial = new int[n];
        factorial[0] = 1;
        for (int i = 1; i < n; i++) factorial[i] = i * factorial[i-1];
        n--;
        StringBuilder res = new StringBuilder();
        while (n >= 0){
            int t = factorial[n];
            int loc = (int) (Math.ceil((double) k / (double) t)) - 1;
            if (loc == -1) loc = num.size() - 1;
            res.append(num.get(loc));
            num.remove(loc);
            k %= t;
            n--;
        }
        return res.toString();
    }
}
```

