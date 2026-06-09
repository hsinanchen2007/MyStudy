```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t prePos = 0, inPos = 0;
        stack<TreeNode *> stk;
        TreeNode *root = nullptr;
        TreeNode **rightPtr = &root;

        while (prePos < preorder.size()) {
            while (stk.size() && stk.top()->val == inorder[inPos]) {
                rightPtr = &stk.top()->right;
                stk.pop();
                ++inPos;
            }

            bool comeAcross = false;
            while (!comeAcross) {
                TreeNode *&writeback = rightPtr ? *rightPtr : stk.top()->left;
                rightPtr = nullptr;
                writeback = new TreeNode(preorder[prePos]);
                stk.emplace(writeback);

                if (preorder[prePos] == inorder[inPos])
                    comeAcross = true;

                ++prePos;
            }
        }

        return root;
    }
};
```
