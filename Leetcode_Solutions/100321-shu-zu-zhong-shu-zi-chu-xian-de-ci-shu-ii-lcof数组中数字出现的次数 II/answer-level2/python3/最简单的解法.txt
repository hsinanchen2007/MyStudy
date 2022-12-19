采取一个最简单的解法，用一个字典（键为数字，值为出现次数）记录每个字出现的次数。
第一次出现新增字典，值设为1.
不是第一次出现，先把字典对应的键的值加1，然后判断是否等于三次，等于三次就从字典删除
最后剩下的就是一次的，把键取出来即可。

这种方法不在乎有几个单值的，都能找出来，也不在乎其他的是出现两次三次，应该是最容易理解的方法了。
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        mydic = {}
        for i in nums:
            if i not in mydic.keys():
                mydic[i]=1
            else:
                mydic[i]+=1
                if mydic[i]==3:
                    mydic.pop(i)
        L = []
        for k,v in mydic.items():
            L.append(k)
        return L[0]
```
