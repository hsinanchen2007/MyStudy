思路：递归求解.
preorder的第一个元素一定是根，然后在inorder中找到这个根的位置，这个位置之前的是左子树的中序遍历，这个位置之后的是右子树的中序遍历。
然后从preorder中从index=1出发，截取左子树的中序遍历那么多个元素，这个就是左子树的前序遍历，preorder后面剩下的就是右子树的前序遍历。
然后使用递归构造出左子树和右子树，和根节点连接后返回。

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        auto root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return root;
        }
        int leftIndex = 0;
        while (inorder[leftIndex] != preorder[0]) {
            leftIndex++;
        }
        vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin()+ leftIndex);
        vector<int> rightInorder = vector<int>(inorder.begin()+ leftIndex+1, inorder.end());
        vector<int> leftPreorder = vector<int>(preorder.begin()+1, preorder.begin()+leftInorder.size()+1);
        vector<int> rightPreorder = vector<int>(preorder.begin()+leftInorder.size()+1, preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};
```