1.先序遍历 遍历树的每个结点
2.对每个结点做一次深度优先搜索（因为路径可以从任一结点开始，且不一定在叶子结点结束），考虑所有父结点 --> 子结点的可能路径
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:

        # self.res = []
        self.sum = sum
        self.num = 0
        self.pre_order(root)
        return self.num

    def pre_order(self, root):
        if not root:
            return
        # 访问 根结点
        self.dfs(root, [], self.sum) # 这里的第二个参数没有用到；在下面的第二种写法中才会用到，但是会超时，不够高效。
        self.pre_order(root.left)
        self.pre_order(root.right)
    
    def dfs(self, root, path, sum):
        if not root:
            return 
        sum -= root.val
        if sum == 0:
            self.num += 1
        self.dfs(root.left, [], sum)
        self.dfs(root.right, [], sum)
        
        # 下面这种写法会卡在最后两个测试用例上，报“超出时间”的错误
        # if root and sum(path) + root.val == self.sum:
        #     self.res.append(path + [root.val, ])
        #     print('get one:', path + [root.val, ])
        #     # return 
        # if root.left:
        #     self.dfs(root.left, path + [root.val, ])
        # if root.right:
        #     self.dfs(root.right, path + [root.val, ])
```
