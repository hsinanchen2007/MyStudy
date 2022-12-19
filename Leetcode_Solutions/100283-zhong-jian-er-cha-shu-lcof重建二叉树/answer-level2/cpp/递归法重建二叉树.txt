### 解题思路
需要首先熟悉二叉树先序遍历与中序遍历的规则。
先找到preorder中的起始元素作为根节点，在inorder中找到根节点的索引mid；那么，preorder[1:mid + 1]为左子树，preorder[mid + 1:]为右子树；inorder[0:mid]为左子树，inorder[mid + 1:]为右子树。递归建立二叉树。

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
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        TreeNode* treeNode = new TreeNode(preorder[0]);
        int mid = distance(begin(inorder), find(inorder.begin(), inorder.end(), preorder[0]));
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> right_pre(preorder.begin() + mid + 1, preorder.end());
        vector<int> left_in(inorder.begin(), inorder.begin() + mid);
        vector<int> right_in(inorder.begin() + mid + 1, inorder.end());

        treeNode->left = buildTree(left_pre, left_in);
        treeNode->right = buildTree(right_pre, right_in);
        return treeNode;
    }
};
```

![捕获.JPG](https://pic.leetcode-cn.com/8cc24805015a8acee6e8df4cac9fe31005e3fb4430ce9c439f788fff085096d3-%E6%8D%95%E8%8E%B7.JPG)
