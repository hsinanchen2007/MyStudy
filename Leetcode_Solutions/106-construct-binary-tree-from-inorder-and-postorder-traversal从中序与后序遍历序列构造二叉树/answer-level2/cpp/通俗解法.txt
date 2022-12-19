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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int num = postorder.size();
        if(inorder.empty() || postorder.empty())
            return NULL;
        TreeNode* root = new TreeNode(postorder[num-1]);
        vector<int> in_left,in_right,post_left,post_right;

        //找到根节点在中序序列中的位置
        int gen = 0;
        for(int i = 0;i<num;i++)
        {
            if(inorder[i]==postorder[num-1])
            {
                gen = i;
                break;
            }
        }
        for(int i = 0; i < gen; i++)
        {
            in_left.push_back(inorder[i]);
            post_left.push_back(postorder[i]);
        }
        for(int i = gen;i<num-1;i++)
        {
            in_right.push_back(inorder[i+1]);
            post_right.push_back(postorder[i]);
        }
        root->left = buildTree(in_left,post_left);
        root->right = buildTree(in_right,post_right);

        return root;
    }
};
```