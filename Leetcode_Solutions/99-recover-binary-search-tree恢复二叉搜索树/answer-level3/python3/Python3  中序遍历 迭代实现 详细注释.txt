思路: 借鉴其他同学的Java代码, 主题思想是采用中序遍历, 找到要交换位置的两个节点
```
    def recoverTree(self, root: TreeNode) -> None:
        """
        思路: 中序遍历, 找到prev比后面node值大的节点
        """
        stack = []
        curr = root
        prev_node = None
        # 前面节点值比后面node值大的节点
        handle_gt_node = None
        # 要处理的node
        handle_node = None
        
        while curr or len(stack):
            if curr is not None:
                stack.append(curr)
                curr = curr.left
            else:
                node = stack.pop()
                if prev_node and prev_node.val > node.val:
                    # 如果prev_node的值比后面的值大 记录一下handle_gt_node, handle_node
                    if handle_gt_node is None:
                        handle_gt_node = prev_node
                    handle_node = node
                    
                prev_node = node
                curr = node.right
        # 交换位置       
        handle_gt_node.val, handle_node.val = handle_node.val, handle_gt_node.val
```

#### 复杂度分析
时间复杂度: 中序遍历,需要扫描一遍元素, 所以时间复杂度O(n)
空间复杂度:  额外开辟栈空间, 空间复杂度为O(n)
(ps: O(1)时间复杂度暂时还没想到,想到会更新)