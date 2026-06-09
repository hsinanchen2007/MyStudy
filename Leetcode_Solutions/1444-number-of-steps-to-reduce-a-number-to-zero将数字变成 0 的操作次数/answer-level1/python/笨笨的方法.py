### 解题思路
此处撰写解题思路
模拟运算过程，优点是没有额外空间
### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        count=0
        while num!=0:
            if num %2==0:
                num/=2
                count+=1
            elif num %2!=0:
                num-=1
                count+=1
        return count
```