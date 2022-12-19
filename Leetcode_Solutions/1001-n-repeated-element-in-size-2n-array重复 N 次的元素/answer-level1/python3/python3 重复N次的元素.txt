思路1：哈希表，边存边找，找到重复的就可以返回了
思路2：**原列表** 比 **集合化之后的列表** 多了N-1个重复值，相减除下就能得到结果

思路1
```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        dic = {}
        for i in A:
            if i in dic:
                return i
            else: dic[i] = 1
```

思路2
```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        return (sum(A)-sum(list(set(A))))//(len(A)//2-1)
```
