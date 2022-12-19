### 解题思路
根据中序遍历和后序遍历的特点，用分治法的思想，每次递归找到子树节点构造二叉树

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
        int n = inorder.size();
        if(n == 0){
            return NULL;
        }
        return build(inorder, postorder, 0, n - 1, n - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int i, int j, int l){
        if( j < i || l == -1)
            return NULL;
        if(i == j){
            TreeNode* temp = new TreeNode(inorder[i]);
            return temp;
        }
        TreeNode* an = new TreeNode(postorder[l]);
        auto it = find(inorder.begin() + i, inorder.begin() + j, postorder[l]);
        int o = it - inorder.begin();
        int lefto = l - (j - o) - 1;   //右孩子在postordei坐标
        an->left = build(inorder, postorder, i, o - 1, lefto);
        an->right = build(inorder, postorder, o + 1, j, l - 1);
        return an;
    }
};
```