后序遍历和二叉树的后序遍历一样，只不过使用了yield
```py
def postorder(root):

    def postorder_tree_walk(root):
        if root:
            for node in root.children:
                yield from postorder_tree_walk(node)
            yield root.val
        
    return [i for i in postorder_tree_walk(root)]
```