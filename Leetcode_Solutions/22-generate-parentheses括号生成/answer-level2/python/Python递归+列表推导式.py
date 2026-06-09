### 解题思路
![无标题.png](https://pic.leetcode-cn.com/b02465d90f38642644a05a765c1368291199e6397d40f6cc29fe8abdd839e707-%E6%97%A0%E6%A0%87%E9%A2%98.png)
只需要在这几层中插入总数为n的'('就可以了
插入的时候需要注意当前层至少需要插入多少个。


### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int,i=0,j=0,s='') -> List[str]:
        # if n==0:return []
        #i:已使用括号数量
        #j：当前层数
        #minnum当前层数最少需要加上多少个'('
        if i == n:return [s+')'*(n-j)]
        if j == n-1:return [s+'()']
        minnum = j+1-i if j-i+1>0 else 0
        return [y for x in range(minnum,n-i+1) for y in self.generateParenthesis(n,i+x,j+1,s+x*'('+')')] 
```