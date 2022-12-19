思路是从根节点开始，遍历每个节点的左右子树，判断左右子树是否满足要求
注意，以当前节点的所有子树能否被剪枝的条件是：左子树包含1、右子树包含1、当前节点是1，只要有1个条件满足就不应该被剪枝；
程序里有个细节需要注意：dfs的时候不能只用一个valid变量去搜索左右子树，因为可能存在这样的情况：先遍历左子树，满足要求，valid = true; 但右子树不满足要求，valid 被修改为 false。应该定义两个变量 leftValid 和 rightValid 分别判断。
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
    void dfs(TreeNode* root, bool& isValid)
    {
        if(root == nullptr) return;

        bool leftValid = false;
        dfs(root->left, leftValid);
        if(leftValid == false)
        {
            root->left = nullptr;
        }

        bool rightValid = false;
        dfs(root->right, rightValid);
        if(rightValid == false)
        {
            root->right = nullptr;
        }

        isValid = (root->val == 1) || (leftValid || rightValid);
    }

    TreeNode* pruneTree(TreeNode* root) {
        bool isValid = false;
        dfs(root, isValid);

        return root;
    }
};
```
