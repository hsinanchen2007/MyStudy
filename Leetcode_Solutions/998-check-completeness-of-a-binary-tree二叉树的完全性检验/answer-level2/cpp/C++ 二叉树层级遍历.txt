```
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
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool hit_final_parent = false;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left != NULL) {
                if (hit_final_parent) return false;
                q.push(node->left);
            } else {
                hit_final_parent = true;
            }
            if (node->right != NULL) {
                if (hit_final_parent) return false;
                q.push(node->right);
            } else {
                hit_final_parent = true;
            }
        }
        return true;
    }
};
```
![image.png](https://pic.leetcode-cn.com/466ea93bba1e1f83ec5048ae4a57b563e1e60b3198924443c61ce2b369e77308-image.png)
