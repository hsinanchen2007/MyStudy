```
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        h = {}
        nums = list(set(nums))
        for i in nums:
            if i+1 in h and i-1 in h: #如果i+1和i-1都存在，则更新两端头尾
                h[h[i+1][1]][0] = h[i-1][0]
                h[h[i-1][0]][1] = h[i+1][1]
            elif i+1 in h: #如果i+1存在，则更新两端头尾
                h[i+1][0] = i
                h[i] = h[i+1]
            elif i-1 in h: #如果i-1存在，则更新两端头尾
                h[i-1][1] = i
                h[i] = h[i-1]
            else:
                h[i] = [i,i]
        ret = 0
        for i in h:
            ret = max(ret,h[i][1]-h[i][0]+1)
        return ret
```