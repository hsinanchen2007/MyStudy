思路: 利用中序遍历升序的性质, 当元素个数等于k时提前停止遍历,最后一个就是要找的元素

```
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        """
        思路: 采取中序遍历, 当元素个数等于k时停止遍历,最后一个就是要找的元素
        """
        if root is None:
            return root
        
        stack = []
        container = []
        curr = root
        while curr or len(stack):
            if curr is not None:
                stack.append(curr)
                curr = curr.left
            else:
                node = stack.pop()
                container.append(node.val)
                if len(container) == k:
                    break
                curr = node.right
        return container.pop()
```

#### 复杂度分析
时间复杂度: O(k)  (k为给定的k值)
空间复杂度: O(k)