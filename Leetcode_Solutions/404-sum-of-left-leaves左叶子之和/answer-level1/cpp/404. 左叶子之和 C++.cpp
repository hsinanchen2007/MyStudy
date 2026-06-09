### 解题思路
1.找到叶子节点返回该节点的数值，若是非叶子节点就用于取叶子节点之和并向上返回。

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
    int sumOfLeftLeavesHelper(TreeNode* root,bool flag){
        if(root == NULL){
            return 0;
        }
        
        int leave = 0;
        
        if(flag && root->left == NULL && root->right == NULL){
            leave = root->val;
        }
        
        int left = sumOfLeftLeavesHelper(root->left,true);
        int right = sumOfLeftLeavesHelper(root->right,false);
        return left + right + leave;
    }
    
    int sumOfLeftLeaves(TreeNode* root){
        return sumOfLeftLeavesHelper(root,false);
    }
};
```