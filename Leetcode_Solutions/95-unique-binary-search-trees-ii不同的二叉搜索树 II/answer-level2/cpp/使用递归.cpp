### 解题思路
此题借用大神的思路，自己进行梳理，以供加深记忆。

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
    vector<TreeNode*> getTree(int begin, int end){
        vector<TreeNode*> res;
        if(begin >end){
            res.push_back(NULL);
            return res;
        }
        for(int i = begin; i<= end; i++){
            vector<TreeNode*> leftNode = getTree(begin, i-1);
            vector<TreeNode*> rightNode = getTree(i+1, end);
            for(auto left: leftNode){
                for(auto right: rightNode){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode*>();
        }
        return getTree(1, n);
    }
};
```