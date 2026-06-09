### 解题思路
- 递归寻找左右子树都非空的唯一节点
- 在每一个递归函数体中：直接判断、递归判断左右子树、回溯

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root) return nullptr;
        if (root==p || root==q) return root;

        //在左子树中寻找是否存在p或q
        //不存在则赋值为nullptr
        TreeNode *left  = lowestCommonAncestor(root->left, p, q); 
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (!left) return right; //左边没有p或q，返回右边
        if (!right) return left; //右边没有p或q，返回左边
        return root; //左右子树都非空，该节点就是最近公共祖先
        //其实这里漏了左右都没有的情况，但被左边没有返回右边（右边也是空）的情况覆盖了
    }
};
```