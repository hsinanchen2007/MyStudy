### 解题思路
由实例得知其为树的先序遍历，因此先用DFS求出先序遍历序列到ans数组中，然后修改root；一定要注意树为空时的操作，愚蠢的我差点气死。

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
    vector<int> ans;
    void DFS(TreeNode* root){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        DFS(root->left);
        DFS(root->right);
    }
    void flatten(TreeNode* root) {
        DFS(root);
        TreeNode* temp=root;
        if(ans.size()==0){
            root=NULL;
            return;
        }
        root->left=root->right=NULL;
        root->val=ans[0];
        for(int i=1;i<ans.size();i++){
            root->right=new TreeNode(ans[i]);
            root=root->right;
        }
        root=temp;
        return;   
    }
};
```