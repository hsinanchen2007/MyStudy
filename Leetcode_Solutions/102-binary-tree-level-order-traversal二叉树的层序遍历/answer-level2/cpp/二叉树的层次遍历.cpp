### 解题思路
借助队列实现

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //借助队列来实现二叉树的层次遍历
        queue<TreeNode*> q;
        vector<vector<int>> v;
        vector<int> c;
        TreeNode* p=root;
        if(p==NULL)
            return v;
        q.push(p);
        while(!q.empty()){
            int num=q.size();
            for(int i=0;i<num;++i){
                p=q.front();
                c.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                q.pop();
            }
            v.push_back(c);
            c.clear();
        }
        return v;
    }
};
```