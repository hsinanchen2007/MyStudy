
### 思路

- 标签：`动态规划`
- 先要根据题意找到一个规律，规律如下：

```
1 阶:
1
=> 1; 1 个 1

2 阶:
1 1 
2 <= 1 1
=> 1 + 1 = 2;  1 个(末尾) 1

3 阶:
1 1  1
2  1

1 2 <= 1  1 1
=> 2 + 1 = 3;  2 个 1 

4 阶: 
1 1 1  1
2 1  1
1 2  1

1 1  2 <= 1 1  1 1
2  2 <= 2  1 1
=> 3 + 2 = 5;  3 个 1  

5 阶:
1 1 1 1  1
2 1 1  1
1 2 1  1
1 1 2  1
2 2  1

1 1 1  2 <= 1 1 1  1 1
2 1  2 <= 2 1  1 1
1 2  2 <= 1 2  1 1
=> 5 + 3 = 8; 5 个 1
```

规律总结：

- 当前阶的方法数跟上一阶的方法数相关
- 当前阶的方法数等于上一阶的方法数 + 上一阶末尾为 1 的数量
- 当前阶末尾为 1 的数量等于上一阶的方法数

### 代码

将规律转换为代码：

- curr = res[-1] + res[-2] （Python 思想： res[-1] 为数组倒数第一个，res[-2] 为数组倒数第二个）

```python []
# Python3 
class Solution:
    def climbStairs(self, n: int) -> int:
        res = [0,1] # res -> result
        for x in range(n):
            res.append(res[-1] + res[-2])
        return res[-1]
```

- 时间复杂度：O(n)，需要运行 n 次
- 空间复杂度：O(n)，需要一个长度为 n 的数组

节省空间，让数组长度保持在 2

```python []
# Python3 
class Solution:
    def climbStairs(self, n: int) -> int:
        res = [0,1] # res -> result
        for x in range(n):
            res.append(res[-1] + res[-2])
            res.pop(0)
        return res[-1]
```

换一种方式：只需要两个元素即可，使用变量，不使用数组，result[-1] => y; result[-2] => x

```python []
# Python3 
class Solution:
    def climbStairs(self, n: int) -> int:
        x,y,temp = 0,1,0
        for i in range(n):
            temp = y
            y = x + y
            x = temp
        return y
```

疑问：第二和第三种方式为什么没有节省空间？按理说空间复杂度应该是 O(1)

![](https://pic.leetcode-cn.com/3cd9e40baf70434a42e56a6eaf342db58930ce9f44b54d311a4cfa8ddb60aceb.png)
