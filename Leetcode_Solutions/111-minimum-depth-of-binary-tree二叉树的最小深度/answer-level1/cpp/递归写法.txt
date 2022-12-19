```
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)  //判断本节点为空 ，则返回0  因为这个节点不存在了。
        {
            return 0;
        }
        int left = minDepth(root->left);  //递归获得左子树的长度
        int right = minDepth(root->right);//递归获得右子树的长度
        int result; 
        if(root->left && root ->right) //如果左右子树都存在的话
        {
            result = min(left,right)+1; //就取二者中小的一个返回值 因为要求最小值
        }
        else{//如果只有一个子树存在 或者左右子树都不存在
            result = left +right +1; // 就返回左子树加右子树+1的值  
            //不存在的那个树的值为0
        }
        return result;
    }
};
```
