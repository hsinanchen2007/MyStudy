### 解题思路
1.需要用到两个栈，第一个栈为node_stack用于深度遍历二叉树，第二个栈为sum_stack用于存放剩余路径数量。
2.当还没有达到叶子结点时，需要把它的左右子结点压入栈中同时，把当前剩余路径数量减去左右子节点的值。
3.不断检查栈内元素，当遍历到叶节点且当前剩余路径数量为0时则返回true，即存在。若栈为空仍没有使当前剩余路径数量为0则返回false。

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
    bool hasPathSum(TreeNode* root, int sum) {
            if(root == NULL){
        return false;
    }

    stack<TreeNode*> node_stack;
    stack<int> sum_stack;
    node_stack.push(root);
    sum_stack.push(sum - root->val);

    TreeNode* node;
    int curr_sum;
    while(!node_stack.empty()){
        node = node_stack.top();
        node_stack.pop();
        curr_sum = sum_stack.top();
        sum_stack.pop();

        if(node->left == NULL && node->right == NULL && curr_sum == 0){
            return true;
        }

        if(node->right != NULL){
            node_stack.push(node->right);
            sum_stack.push(curr_sum - node->right->val);
        }

        if(node->left != NULL){
            node_stack.push(node->left);
            sum_stack.push(curr_sum - node->left->val);
        }
    }
    return false;
    }
};
```