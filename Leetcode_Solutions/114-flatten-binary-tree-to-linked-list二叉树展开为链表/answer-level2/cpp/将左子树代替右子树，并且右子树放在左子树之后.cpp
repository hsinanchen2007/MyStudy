### 解题思路
1、用栈存放所有的右子树。
2、当左子树为空，或者左子树已经访问过，将前置节点父之过当前节点的右子树，并且将当前节点的左子树设置为空。
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
        while(cur||!mystack.empty()){
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