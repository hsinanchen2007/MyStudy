### 解题思路
与  124. 二叉树中的最大路径和 一题 思想相似，细节不同
当前节点的值与其子节点值的相同与否来决定返回值

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
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(!root->left&&!root->right) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        int sum=0,f1=0,f2=0;
        if(root->left!=NULL){
            if(root->left->val==root->val){
                 sum+=left+1;f1=1;
            }
        }
        if(root->right!=NULL){
             if(root->right->val==root->val){
                f2=1;sum+=right+1;
             } 
        }
        ans=max(sum,ans);
        if(f1&&f2){//左右都相同，取最大值
           return max(left,right)+1;
        }
        else if(f1){
           return left+1;
        }
        else if(f2){
            return right+1;
        }
        return 0;//左右都不同，返回0
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }
};
```