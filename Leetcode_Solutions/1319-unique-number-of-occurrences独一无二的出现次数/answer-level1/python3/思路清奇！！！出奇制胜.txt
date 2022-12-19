将每个元素出现的次数放到空列表中，然后对比去重前后列表的长度，长度一样说明每个元素出现的次数是独一无二的，返回Ture，反之
```
class Solution(object):
    def uniqueOccurrences(self, arr:list):
        """
        :type arr: List[int]
        :rtype: bool
        """
        a = list(set(arr))
        b = []
        for i in a:
            counts = arr.count(i)
            b.append(counts)
        if len(set(b)) == len(b):
            return True
        else:
            return False
```
