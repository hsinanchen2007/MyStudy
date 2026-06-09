### 解题思路
左右单旋可能超时，既然是AVL，可以考虑二分构造一棵树
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
    vector<int> tmp;
    void dfs(TreeNode* root){
        if(root!=NULL){
            tmp.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
        else
            return;
        
    }
    TreeNode* getBalance(vector<int> &tmp,int low,int high)
    {
        if(low>high){
            return NULL;
        }
        else{
            int mid=(low+high)/2;
            TreeNode* ro=new TreeNode;
            ro->val=tmp[mid];
            ro->left=getBalance(tmp,low,mid-1);
            ro->right=getBalance(tmp,mid+1,high);
            return ro;
        }
       
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        sort(tmp.begin(),tmp.end());
        TreeNode*ro=getBalance(tmp,0,tmp.size()-1);
        return ro;
    }
};
```