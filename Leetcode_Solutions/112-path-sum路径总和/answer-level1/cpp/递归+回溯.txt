### 解题思路
思路很简单，见代码

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
    void traversingTree(TreeNode* root, int &sum, bool &flag, int target){
        if (root == NULL) return ;
        if (root -> left == NULL && root -> right == NULL){
            if (sum + root->val == target){
                flag = true;
                return ;
            }
        }
        sum += root -> val;
        if (!flag)
            traversingTree(root->left, sum, flag, target);
        if (!flag)
            traversingTree(root->right, sum, flag, target);
        sum -= root -> val;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        int sum_temp = 0; 
        bool flag = false;
        traversingTree(root, sum_temp, flag, sum);
        return flag;
    }
};
```