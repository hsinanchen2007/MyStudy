### 解题思路
解释请看注释，通俗易懂

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
        // 法1 - 迭代
        if(root == nullptr) return false;
        // 维护一个栈，记录DFS时的节点信息
        stack<pair<TreeNode*, int>> s;
        // 头节点入栈
        s.push(make_pair(root, sum - root->val));
        // 定义两个变量，方便下面 while 循环中使用
        TreeNode* curNode = new TreeNode(0);
        int res;
        while(!s.empty()){
            curNode = s.top().first;
            res = s.top().second;
            // 栈顶元素出栈
            s.pop();
            // 当前节点为叶子节点 且 根节点到当前节点路径和为 sum
            if(!curNode->left&& !curNode->right && !res)
                return true;
            // 如果当前节点右子节点存在，入栈
            if(curNode->right)
                s.push(make_pair(curNode->right, res - curNode->right->val));
            // 如果当前节点左子节点存在，入栈
            if(curNode->left)
                s.push(make_pair(curNode->left, res - curNode->left->val));
            // 注意了，先入右子节点，再入左子节点，以保证二叉树从左往右有方向的层次遍历，不过对于这题无所谓，先入谁都行，反正都要遍历到
        }
        return false;   // 栈空，却还没有满足要求的节点，返回 false

        // 法2 - 递归 - DFS
        if(root == nullptr) return false;
        if(!root->left && !root->right) return sum - root->val == 0;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```