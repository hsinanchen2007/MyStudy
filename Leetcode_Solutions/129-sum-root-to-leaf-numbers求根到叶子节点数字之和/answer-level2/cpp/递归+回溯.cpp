### 解题思路
思路简单，见代码

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
    void traversing_Tree(TreeNode* root, int &temp_sum, int &sum){
        if (root == NULL) return;
        temp_sum = temp_sum*10 + root->val;
        if (root -> left == NULL && root -> right == NULL){
            sum += temp_sum;
        }
        traversing_Tree(root->left, temp_sum, sum);
        traversing_Tree(root->right, temp_sum, sum);
        temp_sum = (temp_sum - root -> val)/10;
    }
    int sumNumbers(TreeNode* root) {
        int temp_sum = 0;
        int sum = 0;
        traversing_Tree(root, temp_sum, sum);
        return sum;
    }
};
```