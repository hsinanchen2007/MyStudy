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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> left_pre, left_in, right_pre, right_in;
        int index = 0;
        //寻找前序中父节点在inorder中的位置
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i] == preorder[0]){
                index = i;
                break;
            }
        }

        for(int i = 0; i<index; i++){
             left_pre.push_back(preorder[i+1]);
             left_in.push_back(inorder[i]);
        }
        for(int i = index+1; i<preorder.size();i++){
            right_pre.push_back(preorder[i]);
            right_in.push_back(inorder[i]);
        }
        root->left = buildTree(left_pre,left_in);
        root->right = buildTree(right_pre,right_in);
        return root;

    }
};
```