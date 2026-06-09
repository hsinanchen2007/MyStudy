### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        queue = []                                          #最后返回的队列
        cur = [root]                                        #存放的节点信息
        while cur:                                          #当节点信息存在时
            cur_result_val = []                             #存放当层节点值
            next_node = []                                  #存放下一层节点
            for node in cur:
                print(node)
                if node:                                    #遍历cur 如果节点存在
                    cur_result_val.append(node.val)         #将值存入当前层列表中
                    next_node.extend([node.left,node.right])#将node的左右节点存入下一层节点列表中
            if cur_result_val:                              #如果当前层存在
                queue.insert(0,cur_result_val)              #则入队列插入第一个
            cur = next_node                                 #不存在则将下一层当作cur继续循环
        return queue                                        #最后返回最终结果queue
```