### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        if not answers:
            return  0

        d={}
        for cnt in answers:
            d[cnt]=d.get(cnt, 0)+1

        ans=0
        for key, value in d.items():
            if key==0:     #每种都有一个
                ans+=value
            else:
                cnt=key+1
                ans+=((value+cnt-1)//cnt)*cnt  #向上取整
        return ans
```