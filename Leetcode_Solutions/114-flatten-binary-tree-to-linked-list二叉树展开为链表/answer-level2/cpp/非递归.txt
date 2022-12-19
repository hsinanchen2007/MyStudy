### 解题思路
总体原则：
1）用栈保存右子树，保持右子树不被丢掉。
2）pre用来保存
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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        stack<TreeNode*> mystack;
        while(cur || !mystack.empty()){
            while(cur){
                mystack.push(cur);
                cur = cur->right;
            }
            cur = mystack.top();
            if(cur->left == NULL || cur->left == pre){
                mystack.pop();
                cur->right = pre;
                cur->left = NULL;
                pre = cur;
                cur = NULL;
            }
            else{
                cur = cur->left;
            }
        }
    }
};
```