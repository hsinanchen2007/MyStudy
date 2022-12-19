### 解题思路
分治法，递归解决；同时注意增加cache避免重复计算。python2.7貌似不支持@functools.lru_cache, 手动创建dict实现该功能。

python的加减乘除可以用operator.add operator.sub operator.mul 进行，因此定义 op_set = {'+':operator.add,'-':operator.sub,'*':operator.mul}， 根据操作符，直接进行计算，减少代码上的if else判断，更加pythonic

### 代码

```python
class Solution(object):
    def diffWaysToCompute(self, s):
        """
        :type input: str
        :rtype: List[int]
        递归实现
        """
        import operator
        cache={}
        #@backports.functools_lru_cache.lru_cache
        def recursive(l):
            res = []
            if str(l) in cache:
                return cache[str(l)]
            if len(l) == 0:
                return res
            if len(l) == 1:
                return l
            for i,e in enumerate(l):
                if e in op_set:
                    left = recursive(l[:i])
                    right = recursive(l[i+1:])
                    for i in left:
                        for j in right:
                            res.append(op_set[e](i,j))
            # cache[str(l)] = res
            return res

        res = []
        l = []
        start=end = 0
        op_set = {'+':operator.add,'-':operator.sub,'*':operator.mul}
        for end in xrange(0,len(s)):
            if s[end] in op_set:
                l.append(int(s[start:end]))
                l.append(s[end])
                start = end+1
        l.append(int(s[start:end+1]))
        return recursive(l)
```