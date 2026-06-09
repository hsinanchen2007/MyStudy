1. 最开始想到，排序 + 相邻匹配
不是最好，但是比之后的数组方式好一些
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        L = sorted(nums)
        i = 0
        while True:
            if i == len(L) - 1:
                return L[i]
            if L[i] == L[i+1]:
                i += 2
            else:
                return L[i]
        
print Solution().singleNumber([4,1,2,1,2])

```

2. 数组方式
- 慢
- 没有在数据中，则放入数组中；
- 在数据中的数据，则List.remove(该数字)

```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        L = []
        for i in nums:
            if i not in L:
                L.append(i)
            else:
                L.remove(i)
        return L[0]
```


3. 哈希表
- 快
- 不在表中，则插进去
- 在表中dict.pop(i)
- 最后剩下的则是要找的
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dictionary = {}

        for i in nums:
            if i in dictionary:
                dictionary.pop(i)
            else:
                dictionary[i] = 1
        return dictionary.keys()[0]
```

4. 数学方式
- 这个是看到官方解题，觉得很腻害。。。

```
# fast

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # math methods to calculate
        return 2 * sum(set(nums)) - sum(nums)
        
```
