```
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        
        i = 0
        N = len(gas)

        while True:
            total = 0
            count = 0
            t = i
            while total >= 0 and count < N:
                total += (gas[t] - cost[t])
                t = (t + 1)%N
                count += 1
        
            if count == N and total >= 0:
                return t
            else:
                if t <= i:
                    return -1
                i = t
```
代码写的比较烂，这是一类贪心问题，这类贪心问题就是是否能找到一个起点使得在任一时刻：
a[i] >= 0
a[i] + a[i+1] >= 0
a[i] + a[i+1] + a[i+2] >= 0
....

sum(a) >= 0
满足任一时刻数组连续相加一直大于等于0的解，衍生问题也可以为找一个起点，一个数组连续和始终大于等于另一个数组连续和的方案
具体贪心思路就是最开始选0做起点，一直找直到第一个不满足这个性质的i出现，那么以这个i做为起点继续找直到找到最后一个点
反证法很容易证明，假设
a[0]>=0
a[0] + a[1] >=0
...
a[0] + a[1] + a[2] +.....+a[i-1] >= 0
a[0] + a[1] + a[2] +.....+a[i] < 0
假设 0<k<i能作为起点，那么
a[k] + a[k+1] +......+a[i] >= 0
又a[0] + a[1] + ....... + a[k-1] >=0
所以a[0] + a[1] + ....... + a[k-1] + a[k] + a[k+1] +......+a[i] >= 0 
矛盾，因此0-i之间不可能有起点