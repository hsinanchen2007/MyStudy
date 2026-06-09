### 解题思路
没啥好说。。
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
    //所以就是存储每层的最后一个
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
                if(i == size - 1) ans.push_back(top->val);
            }
        }
        return ans;
    }
};
```