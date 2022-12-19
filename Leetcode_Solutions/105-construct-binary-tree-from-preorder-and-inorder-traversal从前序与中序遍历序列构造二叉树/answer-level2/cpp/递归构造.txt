### 解题思路
根据先序遍历确定根节点，递归构造二叉树

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
        TreeNode *res;
        res = buildTrees(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);

        return res;
    }

    TreeNode* buildTrees(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int qi, int qj)
    {
        if(pi > pj) return NULL;
        if(pi == pj) return new TreeNode(preorder[pi]);
        TreeNode* bnode = new TreeNode(preorder[pi]);

        int k = qi;
        while(preorder[pi] != inorder[k]) k++;

        bnode->left = buildTrees(preorder, pi+1, pi+k-qi, inorder, qi, k-1);
        bnode->right = buildTrees(preorder, pi+k-qi+1, pj, inorder, k+1, qj);

        return bnode;
    }
};
```