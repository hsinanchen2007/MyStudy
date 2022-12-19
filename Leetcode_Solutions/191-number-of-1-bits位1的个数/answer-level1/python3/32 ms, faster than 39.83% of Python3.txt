每一位检查就行了

时间复杂度：O(1)O(1) 。运行时间依赖于数字 nn 的位数。由于这题中 nn 是一个 32 位数，所以运行时间是 O(1)O(1) 的。


```
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count += n&1
            n = n >> 1
        return count
```

更好的是我们可以把前面的算法进行优化。我们不再检查数字的每一个位，而是不断把数字最后一个 11 反转，并把答案加一。当数字变成 00 的时候偶，我们就知道它没有 11 的位了，此时返回答案。

时间复杂度：O(1)O(1) 。运行时间与 nn 中位为 11 的有关。在最坏情况下， nn 中所有位都是 11 。对于 32 位整数，运行时间是 O(1)O(1) 的。

作者：LeetCode
链接：https://leetcode-cn.com/problems/number-of-1-bits/solution/wei-1de-ge-shu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

但貌似这样是最快的
```
 return(bin(n).count('1'))
```
或
```
ns = '{0:032b}'.format(n)
        return ns.count('1')
```