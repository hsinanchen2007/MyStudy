### 解题思路
![批注 2020-01-03 093611.png](https://pic.leetcode-cn.com/28678f07705b7935d8b16a82179f8a1800ce27e59a8e775100e7f95451ba2fc7-%E6%89%B9%E6%B3%A8%202020-01-03%20093611.png)

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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>tree;
        tree.push(root);
        while(!tree.empty()){
            int lmax = INT_MIN;
            int size = tree.size();
            for(int i=0; i<size; i++){
                TreeNode *tmp = tree.front();
                tree.pop();
                lmax = max(lmax, tmp->val);
                if(tmp->left) tree.push(tmp->left);
                if(tmp->right) tree.push(tmp->right);
            }
            ans.push_back(lmax);
        }
        return ans;
    }
};
```