### 解题思路
类似于求所有从根到叶节点的路径，只不过是把路径作为数字求和

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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        int path = 0;
        sumNumbersHelp(root, sum, path);
        return sum;
    }
    void sumNumbersHelp(TreeNode* root, int& sum, int path){
        if(!root) return;
        path = path*10 + root->val;
        if(!(root->left) && !(root->right)){
            sum += path;
            return;
        }
        sumNumbersHelp(root->left, sum, path);
        sumNumbersHelp(root->right, sum, path);
    }
};
```