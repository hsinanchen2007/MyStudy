### 解题思路
本题直接利用的是二叉树先序遍历和中序遍历的特点，通过递归来求解出答案。
1、通过先序遍历，拿到第一个节点，即为二叉树根节点；
2、利用该根节点，算出左子树节点数量，右子树节点数量；
3、利用数量和根节点在中序节点中遍历，分别算出当前二叉树**左右子树**的对应先序遍历列表和中序遍历列表；
4、递归求解；

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
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* dfs(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd) {
        if (preBegin > preEnd || inBegin > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preBegin]);
        int curIndex = 0;
        for (int i = inBegin; i <= inEnd; i++) {
            if (inorder[i] == preorder[preBegin]) {
                curIndex = i;
            }
        }
        int leftLen = curIndex - inBegin;
        int rightLen = inEnd - curIndex;
        root->left = dfs(preorder,preBegin + 1, preBegin + leftLen, inorder, inBegin, curIndex - 1);
        root->right = dfs(preorder,preBegin + leftLen + 1, preEnd, inorder, curIndex + 1, inEnd);
        return root;
    }
};
```