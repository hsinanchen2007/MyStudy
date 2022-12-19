将数组存入字典，从大到小遍历字典键，输出满足条件的解
```
class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        dic = {}
        for i in A:
            dic[i] = dic.get(i,0)+1
        l = list(dic.keys())
        l.sort()
        for i in l[::-1]:
            if dic[i]==1:
                return i
        return -1
```
