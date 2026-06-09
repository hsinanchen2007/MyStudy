两重循环实现倒序查找，输出时用zfill()进行修正
```
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        for i in range(23,-1,-1):
            for j in range(59,-1,-1):
                tmp = [int(m) for m in str(i)] + [int(n) for n in str(j)]
                while len(tmp) < 4:
                    tmp.append(0)
                if sorted(tmp) == sorted(A):
                    return str(i).zfill(2) + ':' + str(j).zfill(2)
        return ''
```
