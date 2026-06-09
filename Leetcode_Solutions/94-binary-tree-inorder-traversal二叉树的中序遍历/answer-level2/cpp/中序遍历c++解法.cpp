### 解题思路
先把左子树入栈，直到叶子结点，然后出栈，将出栈的结点的右孩子入栈，然后将右孩子的左子树依次入栈

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
        // 使用非递归算法
        /* 
         中序遍历算法：先左子树，然后中间结点，然后右子树结点
        */
        stack<TreeNode *> stackList;
        vector<int> value;

        if (root == NULL) {
            return value;
        }

        TreeNode *tempNode = root;

        while ((tempNode != NULL) || (!stackList.empty())) {
            while (tempNode != NULL) {
                stackList.push(tempNode);
                tempNode = tempNode->left;
            }

            // 左子树全部入栈后，出栈
            tempNode = stackList.top();
            value.push_back(tempNode->val);
            stackList.pop();
            // temp结点的右孩子
            tempNode = tempNode->right;
        }

        return value;
    }
};
```