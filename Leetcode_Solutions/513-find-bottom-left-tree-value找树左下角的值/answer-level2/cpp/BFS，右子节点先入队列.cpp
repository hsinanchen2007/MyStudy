### 解题思路
BFS,利用队列将每层的节点值遍历，注意右子节点需要先入队列。循环结束的时候，最后一个节点的值就是需要额节点值

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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
        {
            return root->val;
        }
        queue<TreeNode*> qu;
        qu.push(root);

        TreeNode* temp = root;
        while(!qu.empty())
        {
            temp = qu.front();
            qu.pop();

            if(temp->right != NULL)
            {
                qu.push(temp->right);
            }

            if(temp->left != NULL)
            {
                qu.push(temp->left);
            }
        }
        return temp->val;
    }
};
```