```
class Solution:
    def trap(self, height: List[int]) -> int:
        # ================================================
        # (1) 普通的暴力法
        # res = list()
        # for i,n in enumerate(height):
        #     if i==0:
        #         res.append(0) 
        #     elif i< len(height)-1:
        #         l = max(height[0:i])
        #         r = max(height[i+1:])
        #         res.append(max(min(l,r)-n,0))
        #     elif i==len(height)-1:
        #         res.append(0)
        # return sum(res)
        # ================================================
        # (2) 双指针
        ans = 0
        l = 0
        r = len(height)-1
        h = height
        l_max = 0
        r_max = 0
        while l<r:
            if h[l]<h[r]:
                if h[l]>=l_max: l_max = h[l]
                else: ans += l_max - h[l]
                l += 1
            else:
                if h[r]>=r_max: r_max = h[r]
                else: ans += r_max - h[r]
                r -= 1
        return ans
```
