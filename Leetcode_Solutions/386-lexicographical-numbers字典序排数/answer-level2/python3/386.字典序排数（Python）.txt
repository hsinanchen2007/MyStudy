### 解题思路
我们将n个数按照一定的顺序构建成树，然后从左到右对每棵树进行dfs就行了
![](https://pic.leetcode-cn.com/8e1ce2fdb47cf611a2611624f2336a236d793ab98a44251cc14d9e96571cae6b-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200110102349.png)


### 代码

```python []
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        def dfs(cur,n,res): # cur为根结点
            if cur > n:
                return 
            else:
                res.append(cur)
                for i in range(10):
                    if 10 * cur + i > n: # 比如叶子结点为14，而n是13，dfs就结束了
                        return 
                    dfs(10 * cur + i, n, res)
        res = []
        # 对每棵树进行dfs
        for i in range(1,10):
            dfs(i, n, res)
        return res
```
### 复杂度分析
- 时间复杂度: $O(N)$，使用了递归，时间复杂度为进入递归函数的次数，我们遍历了每一个结点，所以时间复杂度是$O(N)$。
- 空间复杂度: $O(1)$