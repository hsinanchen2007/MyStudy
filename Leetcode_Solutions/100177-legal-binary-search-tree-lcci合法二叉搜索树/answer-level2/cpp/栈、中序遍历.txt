### 解题思路
维护一个栈，存储节点值，然后中序遍历二叉树，若当前节点的值不大于栈顶元素，则不为二叉搜索树。
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
    bool ans = true;
    stack<int> ints;
    void isValid(TreeNode* root)
    {
        if(root == NULL) return ;
        isValid(root -> left);
        if(ints.size() && root -> val <= ints.top()) ans = false;
        else ints.push(root -> val);
        isValid(root -> right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return ans;
        isValid(root);
        return ans;
    }
};
```