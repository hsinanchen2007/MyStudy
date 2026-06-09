### 解题思路
此处撰写解题思路

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
    int sum = 0;
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        if(root)    sum++;
        if(root -> left){
            countNodes(root -> left);
        }
        if(root -> right){
            countNodes(root -> right);
        }
        return sum;
        
    }
};
```