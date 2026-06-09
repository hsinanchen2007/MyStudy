## 思路:

删除二叉搜索树节点，有三种情况

1. 该节点为叶子节点

![image-20200324161922790.png](https://pic.leetcode-cn.com/ab7f175812c5f032a988060f06994b34f803328830857ee7ce88d150df5548d1-image-20200324161922790.png)


2. 该节点左右只有一个孩子

![image-20200324162000778.png](https://pic.leetcode-cn.com/6f2ddebaa0bd486d6e22c615e74201a721b59d9132d54b07d59324cbd479115b-image-20200324162000778.png)


3. 该节点左右都有孩子

![image-20200324162057015.png](https://pic.leetcode-cn.com/092472902ca8d406f19445096bbe72fa276e81814292b40cfdb3fe249c3a0838-image-20200324162057015.png)


**注意：本文编码都是找右子树最小值来替换的。**

思路一：不成熟想法，直接按照上面过程模拟即可；

思路二：利用二叉搜索树的性质，找`key`；两种写法（看代码就能明白！）

## 代码:

思路一：不成熟方法

```python
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        dummy = TreeNode(-1)
        dummy.left = root

        def dfs(parent, cur):
            if not cur:
                return
            if cur.val == key:
                # 叶子节点
                if not cur.left and not cur.right:
                    if parent.left == cur:
                        parent.left = None
                    else:
                        parent.right = None
                # 左右节点有一个
                elif not (cur.left and cur.right):
                    child = None
                    if cur.left:
                        child = cur.left
                    else:
                        child = cur.right
                    if parent.left == cur:
                        parent.left = child
                    else:
                        parent.right = child

                # 左右都有节点
                else:
                    # 找右子树最小值
                    tmp_parent = cur
                    tmp = tmp_parent.right
                    while tmp and tmp.left:
                        tmp_parent = tmp
                        tmp = tmp.left
                    # 
                    cur.val = tmp.val
                    if tmp_parent.left == tmp:
                        tmp_parent.left = tmp.right
                    else:
                        tmp_parent.right = tmp.right
                return
            dfs(cur, cur.left)
            dfs(cur, cur.right)

        dfs(dummy, root)
        return dummy.left
```

思路二：通过二叉搜索树性质

写法1：

```python
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:

        # 找cur的后一个节点
        def successor(cur):
            cur = cur.right
            while cur.left:
                cur = cur.left
            return cur
        
        # 找cur的前一个节点
        def predecessor(cur):
            cur = cur.left
            while cur.right:
                cur = cur.right
            return cur
    
        def delete(cur, key):
            if not cur:
                return None
            if key > cur.val:
                cur.right = delete(cur.right, key)
            elif key < cur.val:
                cur.left = delete(cur.left, key)
            else:
                # 叶子节点
                if not cur.left and not cur.right:
                    cur = None
                # 只能一个孩子节点(也可以解决都有左右孩子的))
                elif cur.right:
                    cur.val = successor(cur).val
                    cur.right = delete(cur.right, cur.val)
                else:
                    cur.val = predecessor(cur).val
                    cur.left = delete(cur.left, cur.val)
            return cur
        
        return delete(root, key)
```

写法2

```python
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:

        def delete(root, key, l):
            if not root:
                return l
            if root.val == key:
                return delete(root.right, key, root.left)
            elif root.val < key:
                root.right = delete(root.right, key, l)
                return root
            else:
                root.left = delete(root.left, key, l)
                return root
        
        return delete(root, key, None)
```

