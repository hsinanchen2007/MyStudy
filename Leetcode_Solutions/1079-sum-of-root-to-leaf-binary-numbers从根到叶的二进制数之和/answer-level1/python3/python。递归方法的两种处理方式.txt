Python。第一种方法，位运算

```ruby
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        self.ans = 0
        
        def helper(temp, root):
            temp <<= 1
            temp += root.val
            if not root.left and not root.right:
                self.ans += temp
            else:
                if root.left:
                    helper(temp, root.left)
                if root.right:
                    helper(temp, root.right)
        
        helper(0, root)
        return self.ans
                
```

第２种方法，利用python的int()函数，将字符串转变为数字
```ruby
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        self.ans = 0
        
        def helper(temp, root):
            temp += str(root.val)
            if not root.left and not root.right:
                self.ans += int(temp,2)
            else:
                if root.left:
                    helper(temp, root.left)
                if root.right:
                    helper(temp, root.right)
        
        helper('', root)
        return self.ans
```
