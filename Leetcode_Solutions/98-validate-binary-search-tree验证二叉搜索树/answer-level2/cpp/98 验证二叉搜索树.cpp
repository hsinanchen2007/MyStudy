树的题目很多都可以用递归实现，怎么实现递归：三步，第一步：终止条件，第二步：返回值是什么，第三部：这个递归要实现什么东西？

方法一：

```
class Solution {
public:

    bool is_true(TreeNode* root,int& maxv,int& minv)
    {
        maxv=minv=root->val;
        if(root->left)
        {
            int nowmaxv;
            int nowminv;
            if(!is_true(root->left,nowmaxv,nowminv))
            {
                return false;

            }
            if(nowmaxv>=root->val)
            {
                return false;
            }
            maxv=max(maxv,nowmaxv);
            minv=min(minv,nowminv);
        }
        if(root->right)
        {
            int nowmaxv;
            int nowminv;
            if(!is_true(root->right,nowmaxv,nowminv))
            {
                return false;
            }
            if(nowminv<=root->val)
            {
                return false;
            }
            maxv=max(maxv,nowmaxv);
            minv=min(minv,nowminv);
        }
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        int maxv;
        int minv;
        return is_true(root,maxv,minv);
    }
};
```
方法二：从上往下递归
思路：二叉搜索树的特征是：节点的左子树只包含小于当前节点的数。
                        节点的右子树只包含大于当前节点的数。
                        所有左子树和右子树自身必须也是二叉搜索树。
假如当前节点是上一个节点的左子节点，上一个节点值是5，上一个节点范围是（-无穷，+无穷）。当前节点的范围就变成了（-无穷，4），
就是范围一步一步缩小



```
class Solution {
public:
    bool bst(TreeNode* root,long long minv,long long maxv)
    {
        if(root==NULL) return true;
        if(root->val<minv|root->val>maxv) return false;
        return bst(root->left,minv,root->val-1ll)&&bst(root->right,root->val+1ll,maxv);//因为val有可能是负无穷，减一可能会溢出，所以转成long long 类型
    }




    bool isValidBST(TreeNode* root) {
        return bst(root,INT_MIN,INT_MAX);
    }
};
```
