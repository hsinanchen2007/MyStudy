懒得优化了，直接把821题提交的代码，拿过来稍微改了一下就行了。
```
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        l = []
        index = 0
        seats += seats[::-1]
        for i in seats:
            if i == 1:
                l += [x for x in range(index + 1)][::-1]
                index = 0
            else:
                index += 1
        if index != 0:
            l += [x for x in range(1,index + 1)]
        ans = []
        for i in range(len(l)//2):
            ans.append(min(l[i],l[-(i+1)]))
        return max(ans)
```
