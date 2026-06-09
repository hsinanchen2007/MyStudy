### 解题思路
建立栈，将头节点入栈。
画图！思考四层时的情况。

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
//循环法尝试一下
//用栈来表示递归
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        stack<TreeNode*> s;//建立一个栈
        s.push(root);//根节点入栈
        while(s.size()!=0)
        {
            TreeNode* node=s.top();//出栈
            s.pop();//删除
            if(node==nullptr) continue;
            TreeNode* a=node->left;
            node->left=node->right;
            node->right=a;//交换左右节点
            s.push(node->left);
            s.push(node->right);

        }
        return root;
    }
};
```