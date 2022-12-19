python3,O(n^3)算法是900ms左右，O(n^2)算法164ms，n方算法就是开个两数的hash（n*(n-1)/2），然后再双指针匹配（n*(n-1)/2），但可能判断操作太多了，所以最后只有84%左右

```stata
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n=len(nums)
        r,h=[],{}
        for i in range(n):
            for j in range(i+1,n):
                s=target-nums[i]-nums[j]
                if s not in h:
                    h[s]=[]
                h[s]+=[(i,j)]
        for i in range(n):
            for j in range(i+1,n):
                s=nums[i]+nums[j]
                if s in h:
                    for k in h[s]:
                        a,b=k
                        if a>j:
                            e=[nums[i],nums[j],nums[a],nums[b]]
                            if e not in r:
                                r+=[e]
                            
        return r
```


