### 解题思路
如果是偶数，就变成n / 2
如果是奇数，就向上+1 或 向下-1；

如果碰到一个奇数，到底是向上还是向下呢？这里就可以用递归的思想，取向上和向下中小的，然后变化过去。

### 代码

```java
class Solution {
    public int fun(int n){
        if(n == 1)
            return 0;
        if(n % 2 == 0)
            return 1 + fun(n/2);
        if(n == Integer.MAX_VALUE)
            return fun(n-1);
        return 1 + Math.min(fun(n-1), fun(n+1));
    }
    public int integerReplacement(int n) {
        return fun(n);
    }
}
```