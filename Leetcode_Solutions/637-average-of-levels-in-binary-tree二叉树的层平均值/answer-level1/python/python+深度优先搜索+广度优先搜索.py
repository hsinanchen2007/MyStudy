```

# 深度优先搜索
def averageOfLevels(self, root):
    """
    :type root: TreeNode
    :rtype: List[float]
    """
    def search(root,i):
        if root==None:
            return 
        if i<len(self.sum_list):
            self.sum_list[i] = self.sum_list[i]+root.val
            self.count_list[i] = self.count_list[i]+1.0
        else:
            self.sum_list.append(root.val)
            self.count_list.append(1)

        # 递归实现深度优先搜索，会保证每一层的i具有相同的值
        search(root.left,i+1)
        search(root.right,i+1)
        
    self.sum_list = []
    self.count_list = []
    search(root,0)
    ans = []
    for i in range(len(self.sum_list)):
        ans.append(self.sum_list[i]/self.count_list[i])
    
    return ans

#广度优先搜索
def averageOfLevels(self, root):
    """
    :type root: TreeNode
    :rtype: List[float]
    """
    ans = []
    queue = [root]
    # 一层一层遍历求均值
    while(len(queue)>0):
        sum_,count_ = 0.0,0.0
        layer_node = []
        while(len(queue)>0):
            node = queue.pop()
            sum_ = sum_ + node.val
            count_ = count_+1
            if node.left!= None:
                layer_node.append(node.left)
            if node.right!=None:
                layer_node.append(node.right)

        queue = layer_node
        ans.append(sum_/count_)

    return ans
```
