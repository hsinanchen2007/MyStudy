### 解题思路
把原数组排序后，新建一个比较数组不断修改比较数组的值和排序后的数组数值进行比较，差值累加即可得到结果。

### 代码

```python3
class Solution(object):
    def minIncrementForUnique(self, A):
        if A == []:
            return 0
        A.sort()
        a=A
        l = len(a)
        res = range(a[0],a[0]+l)
        count = 0
        res=list(res)
        for i in range(l):
            if res[i]<a[i]:
                res[i:] = range(a[i],a[i]+l-i)
        for i in range(l):
            if a[i]<res[i]:
                count += res[i]-a[i]
        return count
```