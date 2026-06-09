### 解题思路
分别递归计算左子树右子树深度。

### 代码

```cpp
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
    int count = 0;
    int depth(TreeNode* rt){
            if(rt == NULL){
                return 0;
            }
            int L = depth(rt->left);
            int R = depth(rt->right);
            count = max(count, L + R + 1);
            return max(L, R) + 1;
        }
    int diameterOfBinaryTree(TreeNode* root) {
        count = 1;
        depth(root);
        return count - 1;
        
    }
};
```