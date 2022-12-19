### 解题思路
用两个队列分别来对左右子树进行层次遍历。
不同的是左边层次遍历的时候按从右到左遍历，右边按照正常方法遍历，遍历的同时比较两边的节点即可。

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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> left_queue;
        left_queue.push(root->left);
        queue<TreeNode*> right_queue;
        right_queue.push(root->right);
        while(!left_queue.empty()&&!right_queue.empty())
        {
            TreeNode* cur_left = left_queue.front();
            TreeNode* cur_right = right_queue.front();
            left_queue.pop();
            right_queue.pop();
            if(cur_left == NULL||cur_right == NULL)
            {
                if(cur_left == NULL&&cur_right == NULL)
                    continue;
                return false;
            }
            if(cur_left->val!=cur_right->val)
            {
                return false;
            }
            left_queue.push(cur_left->right);
            left_queue.push(cur_left->left);
            right_queue.push(cur_right->left);
            right_queue.push(cur_right->right);
        }
        return true;
    }
};
```