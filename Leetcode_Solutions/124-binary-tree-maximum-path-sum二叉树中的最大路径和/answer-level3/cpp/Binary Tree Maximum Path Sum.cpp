### 解题思路
特别注意，路径不能分叉，从某个结点出发，一次性到另一个节点，每条边只能经过一次；
所以，如果将某条路径放在原二叉树中，可以将其视为一颗子树，只有子树的根能够进行一次分叉，其余不存在左右孩子均出现在路径的情况；
所以我们可以单独通过递归先来计算由根节点产生单向路径的路径最大值（无分叉）: g(root);
g(root)=max{root->val;root->val+g(root->left);root->val+g(root->right);}
那么再考虑这道题目的最大路径和 : f(root);
如果路径经过root，那么
f(root)=max{root->val,g(root),root->val+g(root->left)+g(root->right);}
如果不经过root，那么
f(root)=max{f(root->right);f(root->left)};

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
    int maxPathSum(TreeNode* root) {
        if(root->right==NULL&&root->left==NULL) return root->val;
        int sum1,sum2,sum3,sum;
        if(root->left==NULL){
            sum1= rootPathSum(root->right)+root->val;
            if(sum1<root->val) sum1=root->val;
            sum3=maxPathSum(root->right);
            return (sum1>sum3)?sum1:sum3;
        }
        if(root->right==NULL){
            sum1= rootPathSum(root->left)+root->val;
            if(sum1<root->val) sum1=root->val;
            sum2=maxPathSum(root->left);
            return (sum1>sum2)?sum1:sum2;
        }
        int m1=rootPathSum(root->left),m2=rootPathSum(root->right);
        m1=m1>0?m1:0;
        m2=m2>0?m2:0;
        sum1= m1+root->val+m2;
        sum2=maxPathSum(root->left);
        sum3=maxPathSum(root->right);
        sum=sum1;
        if(sum<sum2) sum=sum2;
        if(sum<sum3) sum=sum3;
        return sum;
        
    }
    int rootPathSum(TreeNode* root){
        if(root->right==NULL){
            if(root->left==NULL) return root->val;
            else{
                int l=rootPathSum(root->left);
                return ((l>0)?l:0) + root->val;
            }
        }else{
            int r=rootPathSum(root->right);
            if(root->left==NULL){
                return root->val + ((r>0)?r:0);
            }else{
                int l=rootPathSum(root->left);
                int m=0;
                if(m<l) m=l;
                if(m<r) m=r;
                return m+root->val;
            }
        }
    }
};
```