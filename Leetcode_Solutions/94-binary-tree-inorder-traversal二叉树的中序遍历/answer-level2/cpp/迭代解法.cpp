### 解题思路
利用栅返回上一层

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
private:
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re; 
        stack<TreeNode*> s;   
        while (root || s.size()) {
            //检索到左子树最底端
            while (root) {
                s.push(root);
                root = root->left;
            }
            //已经到达最底端了，开始出栅
            root = s.top();
            re.push_back(root->val);
            s.pop();
            root = root->right;
        }
        return re;
    }
};
```