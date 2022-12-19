## 思路
### 代码
```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend) {
        if (pstart > pend) return nullptr;
        TreeNode *root = new TreeNode(preorder[pstart]);
        auto it = find(inorder.begin() + istart, inorder.begin() + (iend + 1), root->val);//在当前范围内查找，提升一定性能
        int index = it - inorder.begin();
        int lenLeft = index - istart;
        root->left = helper(preorder, pstart + 1, pstart + lenLeft, inorder, istart, index - 1);
        root->right = helper(preorder, pstart + lenLeft + 1, pend, inorder, index + 1, iend);
        return root;
    }
};
```
