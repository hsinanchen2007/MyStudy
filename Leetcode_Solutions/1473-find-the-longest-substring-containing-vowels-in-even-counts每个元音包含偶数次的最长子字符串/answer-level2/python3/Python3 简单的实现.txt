### 解题思路
明天补充，睡觉啦

### 代码

```python3
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        cache={'a':0,'e':0,'i':0,'o':0,'u':0}
        max_=0
        nums=dict()
        nums[(0,0,0,0,0)]=-1
        temp=0
        for i,j in enumerate(s):
            if j in cache:
                num=tuple(cache.values())
                max_=max(i-nums[num]-1,max_)
                cache[j]=(cache[j]+1)%2
                num=tuple(cache.values())
                if num not in nums:
                    nums[num]=i
                else:
                    max_=max(i-nums[num],max_)
                temp=0
            else:
                temp+=1
                max_=max(temp,max_)
        num=tuple(cache.values())
        if num in nums:
            max_=max(len(s)-1-nums[num],max_)
        return max_
```