### 解题思路
枚举j， 找左边大于的 小于的 右边大于的 小于的 相乘就行。
对于每个j,一趟遍历找到左边比当前j大的个数 leftlarge 比当前小的 leftsmall
右边比当前大的 rightlarge,右边比当前小的 righmall,
总数有 i<j<k模式： leftsmall * rightlarge
i>j>K模式: leftlarge * righmall
相加就是总数.

### 代码

```python3
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        for j in range(1,n-1):
            leftlarge = 0
            leftsmall = 0
            rightlarge = 0
            righmall = 0
            for i in range(j):
                if rating[i]<rating[j]:
                    leftsmall+=1
                elif rating[i]>rating[j]:
                    leftlarge+=1
                    
                
            for k in range(j+1,n):
                if rating[j]<rating[k]:
                    rightlarge+=1
                elif rating[j]>rating[k]:
                    righmall+=1
            ans += leftlarge* righmall+ leftsmall*rightlarge
        return ans
```