```
执行用时: 40 ms, 在所有 C++ 提交中击败了81.36%的用户
内存消耗: 17.8 MB, 在所有 C++ 提交中击败了84.75%的用户
```
BST的定义可以描述为：对每一个节点，左子树最右节点值<当前节点值<右子树最左节点值。
在本题中，可以根据以上定义递归调整，使得树有序。
对不满足条件“左子树最右节点值<当前节点值”或者“当前节点值<右子树最左节点值”的节点，交换两个节点值。
每次至少能处理一个节点，一旦发生交换，则当前树不一定有序，继续下一次判断，直到树有序。
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
    void recoverTree(TreeNode* root) {
        while(!is_bst(root));
    }
    bool is_bst(TreeNode* root) {
        if(!root) return true;
        if(root->left) {
            TreeNode* node = root->left;
            while(node->right) node = node->right;
            if(node->val>root->val) {
                int tmp = node->val;
                node->val = root->val;
                root->val = tmp;
                return false;
            }
            if(!is_bst(root->left)) return false;
        }
        if(root->right) {
            TreeNode* node = root->right;
            while(node->left) node = node->left;
            if(node->val<root->val) {
                int tmp = node->val;
                node->val = root->val;
                root->val = tmp;
                return false;
            }
            if(!is_bst(root->right)) return false;
        }
        return true;
    }
};
```