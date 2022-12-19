### DFS遍历
![image.png](https://pic.leetcode-cn.com/ad66a84c794f62f2d675ac9bb12d598cd4a548db04b551ce927c32e494838694-image.png)

- 思路还是很明确的!
- 使用 DFS 遍历整个树的过程中,保存好每一条路径的节点,直到到达叶节点的时候,判断当前存储的路径和是否等于题所给数值,如果是的话,就将结果保存下来,不然的话就一层层的返回,这个过程其实本质上是一个栈的进入与抛出过程.
- 还有一点需要注意的就是,使用`python`时,注意下深拷贝和浅拷贝
- 时间复杂度`O(n)`,`n`为节点个数.空间复杂度为`O(m))`,`m`为所要存储的最终路径的节点个数
- 同时大家注意下浅拷贝和深拷贝的问题啊

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        result = []
        temp = []

        def dfs(root, sum_):
            if root:
                if not root.right and not root.left: #判断是否为叶节点
                    temp.append(root.val)
                    if sum(temp) == sum_:# 满足条件,则添加到最终结果中
                        result.append(temp[0:]) #此处取切片是为了深拷贝,不然temp的操作会对result进行改变
                    temp.pop()
                    return 
                temp.append(root.val)# 进栈
                dfs(root.left, sum_)
                dfs(root.right, sum_)
                temp.pop()# 出栈
        dfs(root, sum_)
        return result





```