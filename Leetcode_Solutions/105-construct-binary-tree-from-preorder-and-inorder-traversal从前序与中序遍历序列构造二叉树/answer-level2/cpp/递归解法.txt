```
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
    int pre = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int i, int j) {
    if (i<0 || j<0|| i>(inorder.size()-1) || j > (inorder.size()-1) || pre > (inorder.size()-1) || i>j) {
        pre--;
        return NULL;
    }
    if (i==j) return new TreeNode(inorder[i]);

    TreeNode* res = new TreeNode(preorder[pre]);
    int pv = preorder[pre];
    int k = i;
    for (;k<j;k++){
        if (pv == inorder[k]) {
            break;
        }
    }
    pre++;
    res ->left = build(preorder, inorder, i, k-1);
    pre++;
    res ->right =build(preorder, inorder, k+1, j);
    return res;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if (preorder.size() == 0 || inorder.size() == 0)
        return NULL;
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};
```
