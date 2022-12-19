### 解题思路
此处撰写解题思路
![4.png](https://pic.leetcode-cn.com/224117c75566476e8c25e449c29fe82303a82e5e8baed33ac5a1857331aa7bb1-4.png)
### 代码

```python3
class Solution:
    def candy(self, ratings: List[int]) -> int:
        size = len(ratings)
        if (size <= 1): return size
        buff = [0] + [1 for _ in range(size)] + [0]
        ratings = [float('-inf')] + ratings + [float('inf')]
        stack = [0]
        for i in range(1,len(ratings)):
            if ratings[i] < ratings[stack[-1]]:
                stack.append(i)
            else:
                buff[i] = buff[stack[-1]] + 1 if ratings[i] > ratings[stack[-1]] else buff[i]
                j = stack.pop()
                while len(stack) > 0:
                    buff[stack[-1]] = buff[j] + 1 if buff[stack[-1]] <= buff[j] else buff[stack[-1]]
                    j = stack.pop()
                stack.append(i)
        return sum(buff[:-1])
```