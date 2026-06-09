### 解题思路
1.根据先序遍历和中序遍历的字符串规则，拆分出根节点；
2、根据根节点从中序遍历中拆出 左子树的中序遍历字符串，和右子树的中序遍历字符串；
3、根据2中的左子树字符串长度拆出先序遍历的左右子树；
4、递归求解。

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
        return Dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* Dfs(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd) {
        if (preBegin > preEnd || inBegin > inEnd) {
            return nullptr;
        }
        TreeNode* curNode = new TreeNode(preorder[preBegin]);
        int curIndex = 0;
        for (int i = inBegin; i <= inEnd; i++) {
            if (inorder[i] == preorder[preBegin]) {
                curIndex = i;
                break;
            }
        }
        int leftLen = curIndex - inBegin;
        curNode->left = Dfs(preorder, preBegin + 1, preBegin + leftLen, inorder, inBegin, curIndex - 1);
        curNode->right = Dfs(preorder, preBegin + leftLen + 1, preEnd, inorder, curIndex + 1, inEnd);
        return curNode;
    }
};
```