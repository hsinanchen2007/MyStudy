### 解题思路
借助栈实现先序遍历的非递归
- 访问根节点后，
- 先将根节点的右子树入栈，
- 再访问左子树

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
        //前序遍历的非递归实现
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(p||!s.empty()){
            while(p){
                v.push_back(p->val);//访问根节点
                s.push(p->right);//先将右子树入栈
                p=p->left;
            }
            p=s.top();
            s.pop();
        }
        return v;
            
    }
};
```