### 解题思路
每次插入都要从根节点开始比较

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.empty())
            return nullptr;

        TreeNode* root = nullptr;

        for(int i = 0; i < preorder.size(); ++i)
        {
            insert(root, preorder.at(i));
        }

        return root;
    }

    void insert(TreeNode*& node, int val)
    {
        if(node == nullptr)
            node = new TreeNode(val);
        
        if(val < node->val)
            insert(node->left, val);

        else if(val > node->val)
            insert(node->right, val);
    }
};
```