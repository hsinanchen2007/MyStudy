什么时候能开到下一个加油站: 
    油箱的油 >= 到下一站消耗的油
    油箱的油: 上一站剩下的油 + 这一站加的油
    到下一站消耗的油: cost[i]
    
性质： 
如果以A为起点, 刚好到点B无法开到B的下一个节点, 那么A~B中的任一起点都不可能作为起点

反证： 
  1. 假设 A到B 之间存在点C可以作为起点
  2. 那么从C到B的下一个点(B+1)剩下的油>=0
  3. A到C 剩下的油肯定要>=0 (A到B途中有途不能<0, 否则就走不到B了)
  4. A到B+1 剩下的油肯定也会>=0
  5. 与A为起点到不了B+1矛盾  

所以 如果以A为起点, 刚好到点B无法开到B的下一个节点, 那么A~B中的任一起点都不可能作为起点


```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        i = 0
        while i < n:
            # g 表示剩余油量
            g = gas[i]
            for j in range(i, i + n):
                # 模拟开车和加油
                g -= cost[j % n]
                # 中间油量不够开到下一站, gg
                if g < 0:
                    i = j + 1
                    break
                g += gas[(j + 1) % n]
            # 正常结束for循环 表示能循环走一圈, 返回 i
            else:
                return i
        return -1
```