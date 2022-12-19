### 解题思路
![截屏2020-03-10上午11.38.00.png](https://pic.leetcode-cn.com/dfbb2e6d93973552b5a6bd0dabda98a5774ce63f983bace505adba97854dda3a-%E6%88%AA%E5%B1%8F2020-03-10%E4%B8%8A%E5%8D%8811.38.00.png)


### 代码


```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0
        def dfs(root):
            if not root: return 0
            left = dfs(root.left)
            right = dfs(root.right)
            self.ans = max(self.ans, left + right)

            return max(left + 1, right + 1)
        dfs(root)
        return self.ans
        
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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode * root){
        if (!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        ans = max(ans, left + right);

        return max(left + 1, right + 1);
    }
};
```