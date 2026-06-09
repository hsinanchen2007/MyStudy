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
private:
    int ans=0;
public:
    //DFS过程，其实返回值意义不大，只有最后返回答案需要，中间是先序遍历
    int pathSum(TreeNode* root, int sum){
        if(root==nullptr) return 0;
        helper(root,sum);//如果是先序遍历（中左右）的话，这里应该输出当前根节点值，此时是调用递归函数计算可行解
        //cout<<root->val<<" "; //这里注释后可以看得很清楚是先序遍历
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return this->ans;
    }
    //对于每一个节点递归计算当前所有可行解
    int helper(TreeNode* root,int sum){
        if(root==nullptr) return 0;
        if(root->val==sum) this->ans++;//如果当前节点是需要找的sum值，那么应该是找到了一个答案
        helper(root->left,sum-root->val);//递归查找，向左向右都要包括根节点，因为在DFS过程中是不考虑之前的父节点的
        helper(root->right,sum-root->val);
        return 0;
    }
};
```
因为二叉树与递归这类题目时常思路不够顺畅，所以写一写，自我清晰一下思路。希望也能帮到大家。
