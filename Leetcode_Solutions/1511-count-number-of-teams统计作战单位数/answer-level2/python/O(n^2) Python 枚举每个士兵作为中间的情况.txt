
```
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        # 枚举每个士兵作为中间
        for i in range(1,n-1):
            #print(rating[i])
            # 左小右大
            l1,r1= 0,0
            # 左大右小
            l2,r2 =0,0
            for j in range(i-1,-1,-1):
                if rating[j] < rating[i]:
                    l1 += 1
                else:
                    l2 += 1
            for j in range(i+1,n):
                if rating[j] > rating[i]:
                    r1 += 1
                else:
                    r2 += 1
            #print(ans)
            # 排列组合
            ans += l1*r1 + l2*r2
        return ans
```
