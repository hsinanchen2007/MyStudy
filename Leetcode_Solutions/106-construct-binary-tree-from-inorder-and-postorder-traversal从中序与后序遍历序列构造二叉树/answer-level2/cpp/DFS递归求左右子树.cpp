### 解题思路
1、根据后序遍历确定根节点；
2、通过根节点确定中序遍历的左右子树长度和对应根节点所在index；
3、通过左右子树长度计算后续遍历的左右子树index；
4、递归求取左右子树；
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
        return Dfs(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* Dfs(vector<int>& postorder, int postBegin, int postEnd, vector<int>& inorder, int inBegin, int inEnd) {
        if (postBegin > postEnd || inBegin > inEnd) {
            return nullptr;
        }
        TreeNode* curNode = new TreeNode(postorder[postEnd]);
        int curIndex = 0;
        for (int i = inBegin; i <= inEnd; i++) {
            if (inorder[i] == postorder[postEnd]) {
                curIndex = i;
                break;
            }
        }
        int leftLen = curIndex - inBegin;
        curNode->left = Dfs(postorder, postBegin, postBegin + leftLen - 1, inorder, inBegin, curIndex - 1);
        curNode->right = Dfs(postorder, postBegin + leftLen, postEnd - 1, inorder, curIndex + 1, inEnd);
        return curNode;
    }
};
```