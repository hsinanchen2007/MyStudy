从二叉搜索树的性质出发——中序遍历是递增序列。
如下图所示：
![image.png](https://pic.leetcode-cn.com/287cdf25a1bcd73b626f48a6a2294c93304dd5555cf4b910d0c622074885b219-image.png)
图中所举的例子为1 2 3 4 5，我们交换其中的2和4.
再次观察新序列，可以发现两个交换过的数都会出现右边小于左边的现象。
显然第一个框内第一个数是需要交换的数，第二个框内第二个数是需要交换的数。
那么就有如下代码
```
class Solution {
public:
    TreeNode*a=NULL;
    TreeNode*b=NULL;
    TreeNode*pre=NULL;
    void findNode(TreeNode* root){
        if(!root){
            return;
        }
        findNode(root->left);
        if(pre&&root->val<=pre->val){
            if(!b){ //记录第一个数
                a=pre;
                b=root;
            }else{  //记录第二个数
                b=root;
            }
        }
        pre=root;
        findNode(root->right);
    }
    void recoverTree(TreeNode* root) {
        findNode(root);
        int tmp=a->val; //交换
        a->val=b->val;
        b->val=tmp;
    }
           
};
```
