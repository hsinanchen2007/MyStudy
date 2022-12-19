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
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty())
        {
            TreeNode* curr = queue.front();
            queue.pop_front();
            if(curr->left != nullptr)
                queue.push_back(curr->left);
            if(curr->right != nullptr)
                queue.push_back(curr->right);
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
        } 
        return root;
    }
};
```