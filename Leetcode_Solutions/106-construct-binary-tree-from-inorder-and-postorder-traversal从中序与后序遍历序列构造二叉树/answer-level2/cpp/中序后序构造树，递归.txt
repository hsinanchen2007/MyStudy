### 解题思路
同先序中序构造树

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
        int inh = inorder.size() -1;
        int posth = postorder.size()-1;
        return in_post_tree(inorder, postorder, 0, inh, 0, posth);
    }

    TreeNode* in_post_tree(vector<int>& inorder, vector<int>& postorder,
                           int inl, int inh, int postl, int posth)
    {
        if(posth < postl) return nullptr;
        TreeNode* t = new TreeNode(0);
        t->val = postorder[posth];
        int mid = inl;
        int temp = postorder[posth];
        while(inorder[mid] != temp)
            mid++;
        t->left = in_post_tree(inorder, postorder, inl, mid-1, 
                                postl, postl+mid-inl-1);
        t->right = in_post_tree(inorder, postorder, mid+1, inh,
                                postl+mid-inl, posth-1);
        return t;
    }
};
```