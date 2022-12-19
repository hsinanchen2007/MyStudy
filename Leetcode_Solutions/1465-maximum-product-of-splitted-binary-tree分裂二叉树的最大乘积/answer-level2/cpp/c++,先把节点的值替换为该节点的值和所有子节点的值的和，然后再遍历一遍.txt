
![image.png](https://pic.leetcode-cn.com/0306aeb9a286fbdbbeef48cbaaf4e76de79b1e130556b97eec9e5abc38c49ef9-image.png)
c++,先把节点的值替换为**该节点的值和所有该节点的子节点的值的和**，替换后，再遍历一遍,找出**[(根节点的值-某个节点的值)*某个节点的值]**的最大值
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
    long long int sum(TreeNode* root){
        if(!root) return 0;;
        if(root->val<=0) return -1*root->val;
        root->val =-1*( root->val+sum(root->left)+sum(root->right));
        return -1*root->val;
        }
    int maxProduct(TreeNode* root) {
        long long int top = sum(root);
        long long int ret = INT32_MIN;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode *p = qu.front();
            if(p->left) qu.push(p->left);
            if(p->right) qu.push(p->right);
            long long int temp = (top-sum(p))*sum(p);
            if(temp>ret) ret = temp;
            qu.pop();
        }
        return ret%(1000000000+7);
    }
};
```
