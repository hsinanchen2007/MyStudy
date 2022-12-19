### 解题思路
类似层序遍历

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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> qu;
        if(root){
            qu.push(root);
        }
        while(!qu.empty()){
            TreeNode *curNode = qu.front();
            qu.pop();
            TreeNode *leftNode = curNode->left;
            curNode->left = curNode->right;
            curNode->right = leftNode;

            if(curNode->left){
                qu.push(curNode->left);
            }

            if(curNode->right){
                qu.push(curNode->right);
            }
        }

        return root;

    }
};
```