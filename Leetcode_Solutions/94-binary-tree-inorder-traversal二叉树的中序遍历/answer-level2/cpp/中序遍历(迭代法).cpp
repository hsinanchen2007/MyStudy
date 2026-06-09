### 解题思路
先将根节点和所有左节点进栈，栈顶元素出栈并处理
若该元素有右节点，指针指向右节点并重复上述操作(所有左节点进栈)
若无右节点，则继续处理栈顶元素(即当前元素的父节点)

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->left;
            }
            p = s.top();s.pop();
            res.push_back(p->val);
            if(p->right) p = p->right;
            else p = NULL;
        }
        return res;
    }
};
```