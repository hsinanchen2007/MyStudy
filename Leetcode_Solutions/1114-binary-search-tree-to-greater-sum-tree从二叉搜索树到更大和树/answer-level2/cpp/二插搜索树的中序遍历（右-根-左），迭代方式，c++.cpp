### 解题思路
1.从右子树开始的中序遍历，采用迭代方式。
2.迭代退出条件：节点为空。迭代过程：右子树--》根节点的值累计并赋给根节点--》左子树
3.返回最终结果

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
    int sum=0;
    int tmp = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root) {
            bstToGst(root->right);
            tmp=root->val;
            sum += tmp;
            root->val = sum;
            bstToGst(root->left);
        }
        return root; // 返回最终的树
    }
};
```