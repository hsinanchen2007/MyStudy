### 解题思路
如果序列为空，则是空树；否则，以先序首元素为根节点，中序中找到根节点，根节点左边的递归建立左子树，根节点右边的递归建立右子树。

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
        int preh = preorder.size()-1;
        int inh = inorder.size()-1;
        return pre_in_tree(preorder, inorder, 0, preh, 0, inh);
    }

    TreeNode* pre_in_tree(vector<int>& preorder, vector<int>& inorder, 
    int prel, int preh, int inl, int inh)
    {
        if(preh < prel) return nullptr;
        TreeNode* node = new TreeNode(0);
        node->val =  preorder[prel];
        int mid = inl;
        int temp = preorder[prel];
        while(inorder[mid] != temp)
            mid++;
        node->left = pre_in_tree(preorder, inorder, prel+1, prel+mid-inl,
                                inl, mid-1);
        node->right = pre_in_tree(preorder, inorder, prel+mid-inl+1, preh,
                                  mid+1, inh);
        return node;
    }
};
```