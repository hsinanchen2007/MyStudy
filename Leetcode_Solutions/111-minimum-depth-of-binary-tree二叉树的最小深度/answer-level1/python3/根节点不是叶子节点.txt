## 思路:

思路很简单, 就是左右子树高度,选最小那个

刚开始我是这样做的

```python
def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
```

但是有个错误例子

```
   1
  /
 2
```

我们的算法求出是`1`,正确答案是`2`,也就是**根节点不能是叶子节点!**

所以,要想办法解决这个问题,我采用是**提前判断是否是叶子节点**!

```python
class Solution:
    def minDepth(self, root: TreeNode) -> int:  
        if not root: return 0
        def helper(root):
            if not root: return float("inf")
            if not root.left and not root.right: return 1
            return min(helper(root.left), helper(root.right)) + 1
        return helper(root)
```

大家可以借鉴一下,网上有更简洁的版本.

```python [1]
def minDepth(self, root: TreeNode) -> int:  
        if not root: return 0
        left = self.minDepth(root.left) 
        right = self.minDepth(root.right) 
        return left + right  + 1 if (left == 0 or right == 0) else min(left, right) + 1 
```



```java [1]
 public int minDepth(TreeNode root) {
        if (root == null) return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        return (left == 0 || right == 0) ? left + right + 1 : Math.min(left, right) + 1;
    }
```

