- 以任意顺序遍历树，当origin和target相等时说明找到了对应节点，返回clone的节点。
```c++
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)return original;
        if(original == target){
            return cloned;
        }
        TreeNode* p = getTargetCopy(original->left,cloned->left,target);    //去左子树找
        TreeNode* q = getTargetCopy(original->right,cloned->right,target);  //去右子树找
        return !p?q:p;  //必然在p q中p为空返回q，不为空直接返回p
    }
};
```