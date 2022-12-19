### 解题思路
后序：右根左（有序递减）
中序：左根右（有序递增）
![截屏2020-03-10下午4.33.18.png](https://pic.leetcode-cn.com/2ceeedaaf551c5e64efdf9a8a3e43006955a7aa7556a87f09c8648524c46b35a-%E6%88%AA%E5%B1%8F2020-03-10%E4%B8%8B%E5%8D%884.33.18.png)

### 可读代码
```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        self.res, self.k = None, k 

        def dfs(node):
            if not node: 
                return
            else:
                dfs(node.right)
                self.k -= 1
                if self.k == 0: 
                    self.res = node.val
                if self.k > 0:
                    dfs(node.left)

        dfs(root)
        return self.res

```
### 代码
```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        self.res, self.k = None, k
        def dfs(root):
            if not root: return 
            dfs(root.right)
            self.k -= 1
            if not self.k: self.res = root.val
            if self.k > 0: dfs(root.left)
        dfs(root)
        return self.res

```


```cpp []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
    void dfs(TreeNode* root, int &k){
        if (!root) return;
        dfs(root->right, k);
        k --;
        if(!k) ans = root->val;
        if(k > 0) dfs(root->left, k);
    }
};
```

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        def inorder(root):
            return inorder(root.left) + [root.val] + inorder(root.right) if root else []
           
        res = inorder(root)
        return res[-k]      
```