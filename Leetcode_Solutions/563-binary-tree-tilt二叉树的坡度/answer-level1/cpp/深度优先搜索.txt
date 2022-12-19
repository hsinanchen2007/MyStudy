### 刚开始我想过用广度优先搜索，但似乎不行，所以用了深度优先搜索，就写出来了


### 代码
class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans=0;
       
        if(root==NULL)return 0;
        answer(root,ans);
        return ans;

        
    }
    int answer(TreeNode*find,int & ans)
    {int left=0,right=0;
        if(find->left==NULL&&find->right==NULL)return find->val;
     if(find->left!=NULL) left= answer(find->left,ans);
     if(find->right!=NULL)   right=  answer(find->right,ans);
     // cout<<ans<<" ";
ans+=(left>right?left-right:right-left);
return (left+right+find->val);
    }
};
```
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
    int findTilt(TreeNode* root) {
        int ans=0;
       
        if(root==NULL)return 0;
        answer(root,ans);
        return ans;

        
    }
    int answer(TreeNode*find,int & ans)
    {int left=0,right=0;
        if(find->left==NULL&&find->right==NULL)return find->val;
     if(find->left!=NULL) left= answer(find->left,ans);
     if(find->right!=NULL)   right=  answer(find->right,ans);
     // cout<<ans<<" ";
ans+=(left>right?left-right:right-left);
return (left+right+find->val);
    }
};
```