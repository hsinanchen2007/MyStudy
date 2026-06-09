## 思路:

十叉树，用题目的测试用例来举例子。

![image-20200314171628883.png](https://pic.leetcode-cn.com/8bb3eab39d780d4bb3f4962ca805a3311f3acc46d3bbd0a7e3f7e057a706cb19-image-20200314171628883.png)


我们求字典序第k个就是上图前序遍历访问的第k节点！但是不需要用前序遍历，如果我们能通过数学方法求出节点1和节点2之间需要走几步，减少很多没必要的移动。

其实只需要**按层节点个数计算**即可，图中节点1和节点2在第二层，因为n = 13，节点1可以移动到节点2（同一层）所以在第二层需要移动1步。

第三层，移动个数就是 (13 - 10 + 1) = 4 `（min（13 + 1， 20） - 10）`

所以节点1到节点2需要移动 1 + 4 = 5 步

当移动步数小于等于`k`，说明需要向右节点移动，图中就是节点1移动到节点2。

当移动步数大于`k`，说明目标值在节点1和节点2之间，我们要向下移动！即从节点1移动到节点10。

## 代码:

```python
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        
        def cal_steps(n, n1, n2):
            step = 0
            while n1 <= n:
                step += min(n2, n + 1) - n1
                n1 *= 10
                n2 *= 10
            return step
                
        cur = 1
        k -= 1
        
        while k > 0:
            steps = cal_steps(n, cur, cur + 1)
            if steps <= k:
                k -= steps
                cur += 1
            else:
                k -= 1
                cur *= 10
        
        return cur
```

