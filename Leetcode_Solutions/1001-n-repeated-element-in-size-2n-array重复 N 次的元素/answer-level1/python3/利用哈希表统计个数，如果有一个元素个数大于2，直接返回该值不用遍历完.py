根据题意：剩余N个元素要占据N个位置，所以他们都是互不相同的，遍历字符串如果有一个元素它的个数大于2就不用在统计下去了，肯定是所求元素
```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        d={}
        for i in A:
            d[i]=d.get(i,0)+1
            if d[i]==2:
                return i
```
