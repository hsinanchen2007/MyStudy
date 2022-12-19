### 解题思路
后序遍历需要保证根结点在左孩子和右孩子访问之后才能访问,因此对于任一结点P,先将其入栈.
(1)如果P不存在左孩子和右孩子,则可以直接访问它;
(2)如果P存在左孩子或者右孩子,但是其左孩子和右孩子都已被访问过了,则同样可以直接访问该结点;
如果非上述两种情况,则将P的右孩子和左孩子依次入栈,这样就保证了每次取栈顶元素的时候,
左孩子在右孩子前面被访问,左孩子和右孩子都在根结点前面被访问。

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
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return v;
    }
    void helper(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        TreeNode* cur = NULL;
        TreeNode* pre = NULL;
        stack<TreeNode*> stack;
        stack.push(root);
        while(stack.size() != 0) {
            cur = stack.top();
            if ((cur->left == NULL && cur->right == NULL) ||
                (pre != NULL && (pre == cur->left || pre == cur->right))) {
                v.push_back(cur->val); // 输出结果
                pre = cur; // 记录已访问的结点
                stack.pop(); // 出栈
            } else {
                // 右孩子较左孩子先入栈
                if (cur->right) {
                    stack.push(cur->right); 
                }
                if (cur->left) {
                    stack.push(cur->left);
                }
            }

        }
    }
};
```