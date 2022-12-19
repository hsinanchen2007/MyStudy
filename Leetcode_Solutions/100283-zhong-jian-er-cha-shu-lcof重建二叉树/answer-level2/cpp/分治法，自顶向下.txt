```C++
class Solution {
public:
    TreeNode* buildCore(std::vector<int>& preorder, std::vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode * root = new TreeNode(preorder[preStart]);
        auto rootIt = find(inorder.begin()+inStart, inorder.begin()+inEnd+1, root->val);
        int rootIdx = distance(inorder.begin(), rootIt);
        int leftLen = rootIdx-inStart;
        root->left = buildCore(preorder, inorder, preStart+1, preStart+leftLen, inStart, inStart+leftLen-1);
        root->right = buildCore(preorder, inorder, preStart+leftLen+1, preEnd, inStart+leftLen+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildCore(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
```
