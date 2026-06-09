对于任何节点来说，其左右子树、以及本身取值都具有一票否决权，任何一项不满足剪枝条件本节点就不能剪，秉承此思想开始愉快的递归
```
class Solution {
public:
    bool NeedCut(TreeNode* root)
    {
        /*如果左右子树都为NULL，那就看本身的值*/
        if (root->left == NULL &&
            root->right == NULL) {
            return root->val == 0 ? true : false;
        }

        bool resl = true;
        if (root->left != NULL) {
            resl = NeedCut(root->left);
            if (resl) {
                root->left = NULL;//剪掉左枝
            }
        }

        bool resr = true;
        if (root->right != NULL) {
            resr =  NeedCut(root->right);//递归判断
            if (resr) {
                root->right = NULL;//剪掉右枝
            }
        }
        /*对于本节点来说，左右子树、本身的值都具有一票否决权，任何一项不满足剪枝条件本节点就不能剪*/
        bool childNeedCut = (resl && resr);
        bool nodeNeedCut = childNeedCut && (root->val == 0 ? true : false);

        return  nodeNeedCut;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        bool nodeNeedCut = NeedCut(root);

        return nodeNeedCut ? NULL : root;//本节点是否要剪
    }
};
```
