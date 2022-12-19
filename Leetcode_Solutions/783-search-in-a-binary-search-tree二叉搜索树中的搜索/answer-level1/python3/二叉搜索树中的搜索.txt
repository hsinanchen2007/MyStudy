### 解题思路
我的思路：递归写法，不写思路了直接看代码叭
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return None
        if root.val == val:
            return root
        elif root.val > val and root.left:
            return self.searchBST(root.left,val)
        elif root.val < val and root.right:
            return self.searchBST(root.right,val)
        else:
            return None
        
```