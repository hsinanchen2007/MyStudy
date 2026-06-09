```
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == NULL) {
            return 0;
        }
        return calSumTree(root, sum);
    }
    
    int calSumTree(TreeNode* root, int sum) {
        int totalSum = 0;
        if (root == NULL) {
            return totalSum;
        }
        sum = 10 * sum + root->val;
        
        totalSum += calSumTree(root->left, sum);
        totalSum += calSumTree(root->right, sum);
        if (totalSum == 0) {
            return sum;
        }
        else {
            return totalSum;
        } 
    }
};
```