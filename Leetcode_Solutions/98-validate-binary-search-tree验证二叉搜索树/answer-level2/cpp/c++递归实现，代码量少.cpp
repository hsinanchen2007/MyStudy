```
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isValidBST(TreeNode* root, std::optional<int> lower, std::optional<int> upper){
        if(!root){
            return true;
        }
        
        if(lower && root->val <= lower.value()) return false;
        if(upper && root->val >= upper.value()) return false;

        
        return isValidBST(root->left, lower, std::optional<int>(root->val)) &&
            isValidBST(root->right, std::optional<int>(root->val), upper);        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, std::nullopt, std::nullopt);
    }
};
```
