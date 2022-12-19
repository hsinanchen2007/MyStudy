一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
先序遍历：

- 每次访问一个节点，那么就将当前权值求和
- 如果当前权值和与期待的和一致，那么说明我们找到了一个路径，保存或者输出
- 每次深度遍历到底部，回退一个点


### 代码

```python
### 前序遍历，深度优先遍历dfs
class Solution(object):
    def __init__(self):
        self.result_all = []
        self.array = []

    def pathSum(self, root, expectNumber):
        if not root: return []
        self.array.append(root.val)
        expectNumber -= root.val
        if expectNumber == 0 and not root.left and not root.right:
            self.result_all.append(self.array[:])
        self.pathSum(root.left, expectNumber)
        self.pathSum(root.right, expectNumber)
        self.array.pop()
        return self.result_all

```