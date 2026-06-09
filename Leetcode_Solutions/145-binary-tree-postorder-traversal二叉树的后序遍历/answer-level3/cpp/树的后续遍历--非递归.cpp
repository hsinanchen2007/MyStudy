### 解题思路
核心思路：
（1）需要有一个标记，标记上一次出栈的节点是谁；
（2）if (cur->right == NULL || cur->right == lastvisit) 
    1）右子数为空（前提是一直遍历到左子树为空）：所以右子数为空，则一定为叶子节点，可以出栈了；
    2）cur->right == lasevisit 说明，上一次出栈的是他的右子树，说明该节点左右子树都出栈了（或者没有左子树）,因此该节点该出战了（换个说法说，就是该节点第二次访问了）
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        std::stack<TreeNode*> stack;
        TreeNode* cur = root;
        TreeNode* lastvisit = NULL;
        while(cur != NULL || !stack.empty()) {
            while(cur != NULL) {
                stack.push(cur);
                cur=cur->left;
            }
            cur = stack.top();
            if (cur->right == NULL || cur->right == lastvisit) {
                result.push_back(cur->val);
                stack.pop();
                lastvisit = cur;
                // 置位空，才能退栈
                cur = NULL;
            } else {
                cur = cur->right;
            }
        }
        return result;
    }
};
```