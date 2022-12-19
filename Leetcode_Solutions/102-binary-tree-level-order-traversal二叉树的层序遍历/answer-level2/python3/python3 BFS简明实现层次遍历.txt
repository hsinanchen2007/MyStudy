```BSF思路 []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        queue = [root]                       #把root初始化一下进去
        out = []
        while queue:
            child = []                       #该轮循环的结果集
            node = []                        #存放while下一次的 数据集
            for item in queue:               #把该次queue里的数据循环一下 添加到 child 
                child.append(item.val)       
                if item.left:
                    node.append(item.left)   #判断当前的数据有没有子节点,有就加到node里
                if item.right:
                    node.append(item.right)
            out.append(child)                #把while这次的结果集放到输出数组里
            queue = node                     #重要! 这是把 node里 搜集的该次循环节点的子节点 放到 queue里 之前漏写这一步就提示超时 我说怎么会超时呢!
        return out
```