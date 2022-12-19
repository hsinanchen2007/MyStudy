l记录连续迟到天数，超过阈值则直接返回FALSE，否则遍历整个数组判断缺席天数。
```
class Solution:
    def checkRecord(self, s: str) -> bool:
        a=0
        l=0
        for r in s:
            if r=='A':
                a+=1
                l=0
            elif r=='L':
                l+=1
            else:
                l=0
            if l==3:
                return False
        return a<2
```

![image.png](https://pic.leetcode-cn.com/9836b06c2bcc3532a7ede1499f341a8c7a82b9761a043542bc1867c8825bcd57-image.png)

