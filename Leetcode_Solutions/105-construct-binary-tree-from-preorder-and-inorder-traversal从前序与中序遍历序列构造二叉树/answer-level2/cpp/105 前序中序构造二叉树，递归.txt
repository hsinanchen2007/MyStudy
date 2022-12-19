### 解题思路
其实就是找到左右子树，在前序中序中的坐标范围，
根节点在前序为最左，
在中序中找到相应位置m
那么有
左子树
前序范围 [l1 + 1, m + l1 - l2]
中序范围 [l2, m - 1]

右子树
前序范围 [r1 + 1 + m - r2, r1]
中序范围 [m + 1, r2]
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
    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1 || l2 > r2) return NULL;
        TreeNode* root = new TreeNode(preorder[l1]);
        int m = l2;
        for (int i = l2; i <= r2; i++) {
            if (inorder[i] == preorder[l1]) {
                m = i;
                break;
            }
        }
        root->left = buildTree2(preorder, inorder, l1 + 1, m + l1 - l2, l2, m - 1);
        root->right = buildTree2(preorder, inorder, r1 + 1 + m - r2, r1, m + 1, r2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return buildTree2(preorder, inorder, 0, len-1, 0, len -1);
    }
};
```