## 思路:

其实对于这种题目,递归不太好想的,可以有个取巧的方法,就是把树转列表,因为结果是按照前序遍历的,所以有:

```python
def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:return root
        d = []
        def helper(root):
            if not root:
                return 
            d.append(root.val)
            helper(root.left)
            helper(root.right)
        helper(root)
        i = 1 
        root.left = None
        p = root
        while i < len(d):
            p.right = TreeNode(d[i])
            p = p.right
            i += 1
```

上面做法属于作弊过的,

思路一: 递归, 类似后序遍历

递归过程:

![image.png](https://pic.leetcode-cn.com/4f800f385b3334c089edae965c19926bbe2227aa5a4b61f5e4471abc2962870b-image.png)


思路二: 迭代,

直接看代码,很容易理解,但是不容易想!

迭代过程：

![image.png](https://pic.leetcode-cn.com/50a2825c3340a122cd48a3125074763e58ef95a17a6c1a2e20014ca075309fd9-image.png)



## 代码:

思路一:

```python [1]
def flatten(self, root: TreeNode, pre = None) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # 类似后序遍历
        def helper(root, pre):
            if not root: return pre
            # 记录遍历时候,该节点的前一个节点
            pre = helper(root.right, pre)
            pre = helper(root.left, pre)
            # 拼接
            root.right = pre
            root.left = None
            return pre
        helper(root, None)
```



```java [1]
class Solution {
    public void flatten(TreeNode root) {
        helper(root, null);
    }

    private TreeNode helper(TreeNode root, TreeNode pre) {
        if (root == null) return pre;
        pre = helper(root.right, pre);
        pre = helper(root.left, pre);
        root.right = pre;
        root.left = null;
        pre = root;
        return pre;
    }
}
```

思路二:

```python [2]
def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        cur = root
        while cur:
            if cur.left:
                p = cur.left
                while p.right: p = p.right
                p.right = cur.right
                cur.right = cur.left
                cur.left = None
            cur = cur.right
```




```java [2]
class Solution {
    public void flatten(TreeNode root) {
      TreeNode cur = root;
        while (cur != null) {
            if (cur.left != null) {
                TreeNode p = cur.left;
                while (p.right != null) p = p.right;
                p.right = cur.right;
                cur.right = cur.left;
                cur.left = null;
            }
            cur = cur.right;
        }
    }
}
```

​    



