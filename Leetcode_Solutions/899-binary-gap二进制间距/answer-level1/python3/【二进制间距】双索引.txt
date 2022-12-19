##### 题目理解：两个连续的1指的是：  1001011中（从左往右）第0，第1个1是一对、第1，第3是一对、第3，第6是一对。连续的两个1中间没有另外的1，只有0,或没有。

##### 思路：用两个变量记录连续两个1的index，找到一对更新一次最大间距。
```
class Solution:
    def binaryGap(self, N: int) -> int:
        i ,j= 0, -1
        result = 0
        while N:
            bit =  N & 1
            N = N >> 1
            if bit:
                if j == -1:
                    j = i
                else:
                    result = max(i-j, result)
                    j = i
            i+=1
        
        return result
```
