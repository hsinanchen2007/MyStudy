### 解题思路
打卡，每个节点都计算左右的最大深度并更新raddium

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
    int radium = 0;
    int search(TreeNode* root){
        if(!root) return 0;
        int l = search(root->left), r = search(root->right);
        radium = radium > l + r + 1 ? radium : l + r + 1;
        return l > r ? l+1 : r+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        search(root);
        return radium-1 > 0 ? radium-1 : 0;
    }
};
```