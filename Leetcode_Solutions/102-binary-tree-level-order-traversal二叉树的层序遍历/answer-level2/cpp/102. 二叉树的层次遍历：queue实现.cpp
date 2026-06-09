### 解题思路
* 利用queue先进先出的特性，只要标记每层最后的节点lvlast，遇到lvlast就将每层的vector存入ans；
* 看出vector.push_back()是用深拷贝。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)    return ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *lvlast = root;
        vector<int> lev;
        while(!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            lev.push_back(tmp->val);
            if(tmp->left)   q.push(tmp->left);
            if(tmp->right)  q.push(tmp->right);
            if(lvlast == tmp) {
                ans.push_back(lev);
                lev.clear();
                lvlast = q.back();
            }
        }
        return ans;
    }
};
```
![2.png](https://pic.leetcode-cn.com/759b1d8f5bab3f132cf62cdf763edeeb3929a70f54910089ad6b746589a5133f-2.png)
