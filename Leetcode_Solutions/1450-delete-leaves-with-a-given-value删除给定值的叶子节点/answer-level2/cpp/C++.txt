### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
         if(root->left!=NULL){
            root->left=removeLeafNodes(root->left,target);
        }
        if(root->right!=NULL){
            root->right=removeLeafNodes(root->right,target);
        }
        if((root->left==NULL&&root->right==NULL)&&root->val==target) root=NULL;
        return root;
    }
};
```