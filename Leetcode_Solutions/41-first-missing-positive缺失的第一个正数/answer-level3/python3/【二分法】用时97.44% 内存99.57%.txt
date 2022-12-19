新手代码

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if nums==[]:
            return 1
        
        nums=list(set(nums))

        def get0(ls, n):
            k = 0
            for i in range(len(ls)):
                if ls[i-k] <= 0:
                    ls.pop(i-k)
                    k += 1

        def getn(ls, n):
            if len(ls)==1:
                if ls[0]==n+1:
                    return n+2
                else:
                    return n+1

            m = math.floor(n +(len(ls)) / 2)
            k = 0
            ls2 = []
            for i in range(len(ls)):
                if ls[i-k] > m:
                    ls2.append(ls[i-k])
                    ls.pop(i-k)
                    k += 1
            if ls==[]:
                return n+1
            elif max(ls)==n+len(ls):
                return getn(ls2, n+len(ls))
            else:
                return getn(ls, n)

        get0(nums, 0)
        if nums==[]:
            return 1
        
        y = getn(nums, 0)
        return y

```