bfs模拟拆盒子的过程

维护几个数组

status: 开着的盒子或者有钥匙的盒子
closed_box: 已经有但是打不开的盒子
queue: 准备要打开的盒子队列

每打开一个盒子都要做三件事:

1. 取钥匙
    - 更新status[i]
    - 开对应的锁着的盒子
2. 取盒子中包含的盒子
    - 已经有钥匙了或者是开着的(status[i]), 添加到队列中
    - 否则添加到closed_box中，等拿到钥匙再打开
3. 取糖果

```python
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        res = 0
        closed_box = [0] * 1010
        q = []      

        for i in initialBoxes:
            if status[i]:
                q.append(i)
            else:
                closed_box[i] = 1
        
        while q:
            cur = q.pop(0)
            
            # 取钥匙
            for i in keys[cur]:
                status[i] = 1
                # 手上有这个盒子, 且这个盒子是关着的, 添加到队列里
                if closed_box[i]:
                    q.append(i)
                    # 注意keys会有很多重复的, 盒子用完记得标记为0
                    closed_box[i] = 0
                    
            # 取糖果
            res += candies[cur]
   
            # 取盒子
            for i in containedBoxes[cur]:
                if status[i]:
                    q.append(i)
                else:
                    closed_box[i] = 1
        return res
```