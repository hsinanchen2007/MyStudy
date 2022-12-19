### 解题思路
此处撰写解题思路

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
    int max_p = 1;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int path = 0;
        depthofnode(root);
        return max_p-1;
    }

    int depthofnode(TreeNode *node){
        if(node == NULL) return 0;
        else{
            int L, R;
            L = depthofnode(node->left);
            R = depthofnode(node->right);
            max_p = max(max_p, L + R +1);
            return max(L, R)+1;
        }
    } 
};
```