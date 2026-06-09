### 解题思路
将节点用颜色标记，标志1表示已经入栈一次，下次在栈中遍历到将输出，标志0表示未曾入栈；
中序遍历中，若节点为标志0，则先将其右子树入栈（非空），再将节点本身入栈（节点标志变为1），再将其左子树入栈（非空）；若节点为标志1，则访问。
### 将make_pair换为pair,效率提高一倍。原因未知

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
    if(root == NULL)
         return {};
    vector<int>res;
    stack<pair<TreeNode * , int>> q;
    q.push(pair(root,0));
    while(!q.empty())
    {
        TreeNode *node = q.top().first;
        int temp = q.top().second;
        q.pop();//先出栈，否则新节点会入栈。
        if(temp == 0)
        {
            if(node->right !=NULL)
                q.push(pair(node->right,0));
            q.push(pair(node,1));
            if(node->left != NULL)
                q.push(pair(node->left,0));
        }
        else
            res.push_back(node->val);
    }
    return res; 
}
};
```