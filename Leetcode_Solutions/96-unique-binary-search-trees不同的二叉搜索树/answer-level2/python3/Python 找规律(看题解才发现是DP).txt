我是找规律做出来的,
首先写一下`n`和对应的结果
```python
0: 1
1: 1    
2: 2 = 1 + 1 # '0' * '1' + '1' * '0'
3: 5 = 1*2 + 1*1 + 2*1  # '0' * '2' + '1' * '1' + '2' * '0'
4: 14 = 1*5 + 1*2 + 2*1 + 5*1 # '0' * '3' + ...
```
含义就是, 我们选定1个位置作为根节点, 然后将左边和右边剩余数字的组合结情况数字相乘.
例如对于 `1 2 3 4`
首先我们将`1`作为根节点,左边为空, 右边有`2 ,3 ,4 `3个数字构成2种5列,一共5种
然后将`2`作为根节点, 左边为`1`,对应1种排列, 右边为`3, 4`构成2中排列, 一共有2种
然后将`3`作为根节点, 同理 2种
最后`4`作为根节点, 同理5种

代码如下
```python
class Solution:
    def numTrees(self, n: int) -> int:
        import functools
        @functools.lru_cache(None)
        def helper(n):
            if n <= 1:
                return 1
            return sum([helper(i) * helper(n - 1 - i) for i in range(n)])
        return helper(n)
```