先遍历一遍把所有子树和求出来 然后判断树的和的一半的子树是否出现过，但是总和为0的时候要判断出现次数大于等于2次才行。比如[0, 0]就应该是true的。

```
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
    
    unordered_map<int, int> m;
    
    
    int dfs(TreeNode *p) {
        if (!p) return 0;
        int x = dfs(p->left);
        int y = dfs(p->right);
        int res = x + y + p->val;
        ++m[res];
        return res;
    }
    
    
    bool checkEqualTree(TreeNode* root) {
        int sum = dfs(root);
        if (sum & 1) return false;
        if (!sum && m[sum] >= 2) return true;
        if (sum && m[sum >> 1]) return true;
        return false;
    }
};
```
