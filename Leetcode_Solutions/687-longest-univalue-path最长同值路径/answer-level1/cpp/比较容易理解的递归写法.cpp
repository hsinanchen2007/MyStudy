### 解题思路
比较容易理解的递归写法，注释写的很全

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
    int ans=0;
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        FindMaxPath(root);
        //递归求出来是结点数，所以要减1
        return ans-1;
    }
    //找到当前根结点左右以及包括自己的最大相同路径长度
    int FindMaxPath(TreeNode* root){
        if(root==NULL) return 0;
        int left=FindMaxPath(root->left);
        int right=FindMaxPath(root->right);
        //左边长度是否作废的判断
        if(!(root->left&&root->val==root->left->val)){
            left=0;
        }
        //右边长度是否作废的判断
        if(!(root->right&&root->val==root->right->val)){
            right=0;
        }
        ans=max(ans,left+right+1);
        cout<<root->val<<" "<<left+right+1<<endl;
        //注意这一步的返回，是一个路径，所以若上层结点和当前的值相同，那么只能从左或右选一条路径
        return max(left+1,right+1);
    }
};
```