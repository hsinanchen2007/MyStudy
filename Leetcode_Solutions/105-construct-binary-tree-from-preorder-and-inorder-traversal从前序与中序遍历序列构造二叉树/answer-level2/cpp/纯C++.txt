### 解题思路
纯C++

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int preorder_index, int inorder_start, int inorder_end)
    {   
        if (preorder_index > preorder.size() - 1 || inorder_start > inorder_end)
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[preorder_index]);
        int index = inorder_start;

        while (index <= inorder_end)
        {
            if (inorder[index] == preorder[preorder_index])
            {
                break;
            }
            index++;
        }

        node->left = helper(preorder, inorder, preorder_index + 1, inorder_start, index - 1);
        node->right = helper(preorder, inorder, preorder_index + (index - inorder_start + 1), index + 1, inorder_end);

        return node;
    }
};
```