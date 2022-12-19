### 解题思路
中序遍历判断是否递增 满足了3个条件。

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
  vector<int>vec;
    bool isValidBST(TreeNode* root) {
       if(root==NULL){
           return true;
       }
       inOrder(root);
       for(int i=1;i<vec.size();i++){
           if(vec[i]<=vec[i-1]){
               return false;
           }
       }
       return true;
    }

    void inOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }

    
};
```