### 解题思路
中序遍历输出平衡树的值，然后用这个已排好序列的数列构建平衡树。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorder_traversal(self, root):
        # re = []
        if root:
            self.inorder_traversal(root.left)
            self.order_list.append(root.val)
            self.inorder_traversal(root.right)
    def construct_avl(self, left, right):
        if left == right:
            re = TreeNode(self.order_list[left])
            return re
        else:
            if left < right:
                mid = int((left+right)/2)
                # print(mid)
                re = TreeNode(self.order_list[mid])
                re.left = self.construct_avl(left, mid-1)
                re.right = self.construct_avl(mid+1, right)
                return re
            else:
                return None
            

    def balanceBST(self, root: TreeNode) -> TreeNode:
        self.order_list = []
        self.inorder_traversal(root)
        print(self.order_list)
        return self.construct_avl(0, len(self.order_list)-1)
        
        

            
```