### 解题思路
哈希表m记录每个节点的最优结果
那么对于root，最优情况只有两种
1.root->val + m[root->left->left] + m[root->left->right] + m[root->right->left] + m[root->right->left]
2.m[root->left] + m[root->right]
取两者最大值即可
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> m;
        return helper(root,m);
        
    }
    
    int helper(TreeNode* root,unordered_map<TreeNode*,int>& m){
        if(!root) return 0;
        if(m.count(root)) return m[root];
        int val = 0;
        if(root->left){
            val += helper(root->left->left,m) + helper(root->left->right,m);
        }
        if(root->right){
            val += helper(root->right->left,m) + helper(root->right->right,m);
        }
        
        m[root] = max(val+root->val,helper(root->left,m)+helper(root->right,m));
        return m[root];
    }
};
```