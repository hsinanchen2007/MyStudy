此处贴出自己的代码
```
class Solution:
    def numberOfSteps (self, num: int) -> int:
        count = 0
        while num!=0:
            if num%2==0:
                num = num/2
                count += 1
            else:
                num -= 1
                count+=1
        return count
```
