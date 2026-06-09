### 解题思路
借助队列迭代解决问题。与广度优先遍历类似，两个两个从队列中取出数据，两数据应该相等，存放顺序：第一个数据的左子树，第二个数据的右子树，第一个数据的右子树，第二个数据的左子树；

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty())
        {
            TreeNode* l = que.front();  que.pop();
            TreeNode* r = que.front();  que.pop();
            if(!l && !r) continue;         //*允许空指针入队列，需要先判断是否为空
            if(!l || !r) return false;

            if(l->val != r->val) return false;
            que.push(l->left);
            que.push(r->right);
            que.push(l->right);
            que.push(r->left);
        }
        return 1;
    }
};
```