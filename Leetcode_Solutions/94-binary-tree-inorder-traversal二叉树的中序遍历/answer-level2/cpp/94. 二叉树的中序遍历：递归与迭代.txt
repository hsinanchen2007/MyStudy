### 解题思路
* 递归与迭代
* 迭代写法参考官方解
* 注意：迭代时使用了一个辅助指针cur，指向当前遍历结点

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
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTra(root);
        return ans;
    }
    void inorderTra(TreeNode *root) {
        if(root == NULL)    return;
        inorderTra(root->left);
        ans.push_back(root->val);
        inorderTra(root->right);
    }
};
```

```cpp
class Solution {
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *cur = root;   
        while(!stk.empty() || cur != NULL) {
            while(cur) {        
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            ans.push_back(cur->val);
            stk.pop();
            cur = cur->right;
        }
        return ans;
    }
};
```