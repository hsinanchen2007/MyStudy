看着代码的注释走

```
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t2 == NULL)
            return true;
        if(t1 == NULL && t2!=NULL)
            return false;
        return helper(t1,t2) || checkSubTree(t1->left,t2) || checkSubTree(t1->right,t2);//当前没找到再往左往右找

    }
    bool helper(TreeNode* t1,TreeNode* t2){
        if(t2 == NULL) //走完t2了
            return true;
        if(t1 == NULL && t2 != NULL)//t2 还没走完t1就走完了 肯定炸
            return false;
        if(t1->val != t2->val)//不相等就炸
            return false;
        return helper(t1->left,t2->left)&&helper(t1->right,t2->right);//左右子树同时满足呗
    }
};
```
