### 解题思路
每转动一次，只能改变某一位的数字，且只能加一或者减一。
用一个队列将与当前数字curnode相邻的节点存储在队列中，并用step+1标记该节点是在第step+1步存放在队列中的（step为curnode节点的标记）。
用集合seen存放被检查过的数字，以免重复运算，造成超时

### 代码

```python3
from collections import deque 
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)#将deadend序列转换为集合，在判断某个数字串是否在deadends中时，时间复杂度较低n(1),
        if target in deadends:
            return -1
        
        queue = deque([('0000',0)])
        seen = {'0000'}
        while queue:
            curnode,step= queue.popleft()
            if curnode == target:
                return step 
            elif curnode in deadends:
                return -1

            for i in range(4):
                for j in (-1,1):
                    newnum = str( (int(curnode[i])+j)%10 )
                    newnode = curnode[0:i] + newnum + curnode[i+1:]
                    if newnode == target:
                        return step+1
                    if (newnode not in deadends) and (newnode not in seen):
                        queue.append((newnode,step+1))
                        seen.add(newnode)
        return -1
```
![image.png](https://pic.leetcode-cn.com/33a78b5904b237b0723e9407c30b250e5e26c428782382b5f0bc7b4362f02304-image.png)
