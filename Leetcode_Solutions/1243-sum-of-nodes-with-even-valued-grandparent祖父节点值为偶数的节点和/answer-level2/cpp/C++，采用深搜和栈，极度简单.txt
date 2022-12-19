### 解题思路
双90%以上的运行效果
思想：维护一个栈，采用先序遍历的方式进行搜索，将当前节点放入栈中。如果这个栈此时的规模大于2，说明此时的深度已经超过了两层，这个节点才能有有效的祖父节点
此时这个祖父节点的位置一定位于栈的倒数第三位，直接读取判断是否为偶数即可
在返回时，弹出这个节点值即可完成维护

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
    int count = 0;
    vector<int>data;
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
        this->dfs(root);
        return this->count;
    }
    void dfs(TreeNode *root)
    {
        if(root == NULL)
        return;
        this->data.push_back(root->val);
        if (this->data.size() > 2)
        {
            if(this->data[data.size()-3] % 2 == 0)
                this->count += root->val;
        }
        this->dfs(root->left);
        this->dfs(root->right);
        this->data.pop_back();
    }
};
```