### 解题思路
链表、树之类的基本都可以通过递归来做，此处找到比目标值大的最小节点，借用一个栈来存储在搜索目标值的过程中比目标值大的，最后返回栈顶的值就必然是比目标值大的最小的那一个

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
    stack<TreeNode *> bigger;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) {
            if (bigger.empty())
                return NULL;
            else
                return bigger.top();
        }
        
        if (p->val < root->val) {
            bigger.push(root);
            return inorderSuccessor(root->left, p);
        } else {
            return inorderSuccessor(root->right, p);
        }
    }
};
```