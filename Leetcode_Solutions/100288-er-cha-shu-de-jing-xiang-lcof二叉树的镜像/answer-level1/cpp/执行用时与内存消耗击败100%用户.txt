### 解题思路
https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
这两道题目是很类似的
要设计一个函数构建一棵树，看到树很容易就想到是递归，要构建树必须返回一个子节点，使得父节点可以和子节点关联，所以函数返回值为树节点的指针
镜像:
1、左节点的值与右节点的值一致
2、左节点的左子树与右节点的右子树一致
3、左节点的右子树与右节点的左子树一致

每次的操作为左节点的值与右节点的值一致
要想满足2 3点，实际上就是保证左子树和右子树每一个节点都满足第一点，故递归产生

考虑特殊情况
1、根节点==NULL
2、根节点的左子树或者是右子树为NULL
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
    TreeNode* copy(TreeNode*src){
        if(!src) return NULL;
        TreeNode* dst  = new TreeNode(src->val);
        dst->right = copy(src->left);
        dst->left = copy(src->right);
        return dst;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return NULL;
        if(!root->left&&!root->right) return root;
        return copy(root);

    }
};
```