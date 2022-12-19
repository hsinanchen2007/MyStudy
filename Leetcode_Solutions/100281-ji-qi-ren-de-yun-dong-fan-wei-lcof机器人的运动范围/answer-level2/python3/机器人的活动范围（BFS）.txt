### 解题思路
**（1）运行结果**
![image.png](https://pic.leetcode-cn.com/463a4350b59a7e73ab50a251b6c4b72145813193ed109f3a2568d5cb98ff3deb-image.png)
**（2）文字思路**
**数位之和：**
给定k值，需要计算坐标x轴和y轴数位总和
可写个函数求数位之和
方便调用判断活动点是否可及
```
def num(x):
    s = 0
    while x:
        s += x % 10
        x = x // 10
return s 
```
其中，x为传入的x轴坐标或y轴坐标

**BFS求可活动点：**
**建立队列queue**
利用先进先出原则
从queue中取出点作为出发点
如果出发点为可活动点
则从出发点行动，可沿x轴或y轴行走一步
所到两点append到queue中
**建立集合seen**
其中值为可活动点
判断从queue中取出的出发点是否可及
如果可及，add到seen中
BFS介绍可参考https://search.bilibili.com/all?keyword=Python%20DFS
**（3）注意tips**
seen为坐标集合，takes exactly one argument
应为seen.add((x,y))，而不是seen.add(x,y)




### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def num(x):
            s = 0
            while x:
                s += x % 10
                x = x // 10
            return s 
        queue,seen = [(0,0,0,0)],set()
        while len(queue):
            x,y,numx,numy = queue.pop(0)
            if not 0<= x <m or not 0<= y <n or k< numx+numy or (x,y) in seen:
                continue
            queue.append((x+1,y,num(x+1),numy))
            queue.append((x,y+1,numx,num(y+1)))
            seen.add((x,y))
        return len(seen)



```