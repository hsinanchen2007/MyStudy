

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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        DLR(root, res);
        return res;

    }


    int DLR(TreeNode* root, int &res){
        if(root==NULL){/*根节点返回0*/
            return 0;
        }

        int vl = DLR(root->left, res);/*递归左子树*/
        int vr = DLR(root->right, res);/*递归右子树*/

        res = max(res, root->val+vl+vr);

        int tmp = max(vl, vr) + root->val;
        return tmp<0? 0:tmp;/*当前节点的左子树加节点值是负数,则返回0*/
    }
};
```
