### 解题思路


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
    int maxProduct(TreeNode* root) {
        if(root == NULL)
            return 0;
        sum = getSum(root);
        DFS(root);
        return (int)(ans % mod);
    }
    long long getSum(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        long long num1 = getSum(node->left);
        long long num2 = getSum(node->right);
        return num1 + num2 + node->val;
    }
    long long DFS(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        long long leftSum = DFS(node->left);
        long long rightSum = DFS(node->right);
        long long leftTotal = leftSum * (sum - leftSum);
        long long rightTotal = rightSum * (sum - rightSum);
        ans = max(ans, max(leftTotal, rightTotal));
        return leftSum + rightSum + node->val;
    }
private:
    long long ans = -0x3f3f3f3f;
    long long mod = 1000000007;
    long long sum = 0;
};
```