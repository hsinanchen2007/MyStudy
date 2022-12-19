### 解题思路
利用栈来实现前序遍历。  前序遍历为 先根，再左子树，再右子树； 先把root压入栈，取栈顶元素，将根出栈，取值放入vector； 再将右子树 和 左子树分别压入栈（注意 先压入右子树）； 循环判断栈是否为空，不为空的话取出栈顶元素，存入数组，再次将该节点的右节点，左节点压入栈。 

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root != NULL) s.push(root);  //根元素入栈
        TreeNode *tmp = NULL;

        while(!s.empty()) {
            tmp = s.top();
            s.pop();    //取出根元素，存入数组
            result.push_back(tmp->val);
            if (tmp->right != NULL) {   //右子树入栈
                s.push(tmp->right);
            }
            if (tmp->left != NULL) {   //左子树入栈， 再次循环的时候，左子树在栈顶，会出栈存入数组；
                s.push(tmp->left);
            }
        }
        return result;

    }
};
```