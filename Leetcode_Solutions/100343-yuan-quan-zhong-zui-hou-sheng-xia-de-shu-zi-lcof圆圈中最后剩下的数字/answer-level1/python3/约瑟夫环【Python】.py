### 思路

**数学**

```
今天笔试正好考了类似的题目，其实就是约瑟夫环。
直接给出递推公式:
```

$$
f(n,m) = \begin{cases} 
		0,\quad n = 1 \\
		[f(n-1,m)+m]\%n,\quad n > 1 
		\end{cases}
$$

##### Python3代码

```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        if n < 1 or m < 1:
            return None
            
        last = 0
        for i in range(2, n + 1):
            last = (last + m) % i
        return last
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/Interview-62-yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/62.py)