经 @joejoejoewu 提醒，现已修改pop() 为 pop(0)。感谢留言指教~~

初始化stack，把root和root.val - target元组一同放入stack中。minval设置为无穷大。
循环：弹出stack，当value v小于minval时，跟通信minval = v, 记录结点值node.val。若target小于node.val且左子树结点存在，将左结点和node.left.val - target压入栈；若target大于node.val且右子树结点存在，将右结点和node.right.val - target压入栈。

```
def closestValue(self, root: TreeNode, target: float) -> int:
        if not root:
            return
        minval, r = float('inf'), None
        stack = [(root, abs(root.val - target))]
        while stack:
            node, v = stack.pop(0)
            if v < minval:
                minval = v
                r = node.val
            if target < node.val and node.left:
                stack.append((node.left, abs(node.left.val - target)))
            if target > node.val and node.right:
                stack.append((node.right, abs(node.right.val - target)))
        return r
```
![最接近的二叉搜索树.PNG](https://pic.leetcode-cn.com/5acca29cf5a6aafb805eac13e9441d5e4fd79f5c8b864506481df1c993890617-%E6%9C%80%E6%8E%A5%E8%BF%91%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.PNG)

