1. 创建两个队列 `rq` 和 `dq` 用于分别存储 `R` 和 `D` 在 `senate` 中的下标值，`length` 代表 `senate` 长度
2. 从队列头部弹出下标值 `r` 和 `d`，比较两者的大小
   - 如果 `r > d`：则保留 `d` 值，将 `d + length` 放置到队列 `dq` 末尾
   - 如果 `r < d`：则保留 `r` 值，将 `r + length` 放置到队列 `rq` 末尾
3. 重复过程 2，直到有队列为空
4. 最终不为空的队列所在阵营宣布胜利！

```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        rq = list()
        dq = list()
        length = len(senate)
        
        for i in range(length):
            c = senate[i]
            if c == "R":
                rq.append(i)
            else:
                dq.append(i)
                
        while len(rq) > 0 and len(dq) > 0:
            r = rq[0]
            d = dq[0]
            
            if r > d:
                # 保留 r
                dq.append(d + length)
            else:
                rq.append(r + length)
                
            del rq[0]
            del dq[0]
            
        return "Dire" if len(rq) == 0 else "Radiant"
```