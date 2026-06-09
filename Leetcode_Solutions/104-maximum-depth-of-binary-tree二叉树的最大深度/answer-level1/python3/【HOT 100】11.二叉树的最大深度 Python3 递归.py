
### 1.看到树就想到递归
看到树就是递归，没啥太复杂的

```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) +1
```

![image.png](https://pic.leetcode-cn.com/e92be062f121a2b007587378f2b231c8125545e8f481bd3b1e206222d1ea4377-image.png)


### 2.扩展
可以看一下这道题：
[二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

[题解](https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/hot-100-9er-cha-shu-de-zhi-jing-python3-di-gui-ye-/)