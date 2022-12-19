## 思路:

没什么好说的, DFS遍历

只不过遍历时候可以记录成字符串(`Python` 写)

也可以`a * 10 + b `(`Java` 写)

都是一样的

## 代码:

```python [1]
def sumNumbers(self, root: TreeNode) -> int:
        self.res = 0
        def helper(root, tmp):
            if not root: return 
            if not root.left and not root.right:
                self.res += int(tmp + str(root.val))
                return   
            helper(root.left, tmp + str(root.val))
            helper(root.right, tmp + str(root.val))
        helper(root, "")
        return self.res
```


```java [1]
class Solution {
    int res = 0;

    public int sumNumbers(TreeNode root) {

        helper(root, 0);
        return res;
    }

    private void helper(TreeNode root, int tmp) {
        if (root == null) return;
        if (root.left == null && root.right == null) res += (tmp * 10 + root.val);
        helper(root.left, tmp * 10 + root.val);
        helper(root.right, tmp * 10 + root.val);
    }
}
```

