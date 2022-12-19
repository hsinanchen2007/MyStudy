### 解题思路
因为没有重复元素，所以可以通过根元素找出左、右子树的前序和中序遍历来递归构造解决。

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