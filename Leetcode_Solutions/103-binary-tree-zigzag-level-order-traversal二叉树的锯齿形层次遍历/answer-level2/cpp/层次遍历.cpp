### 解题思路
经典的使用队列实现层次遍历的模板，通过设置flag来判断是否需要反转当前temp

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n>0){
                TreeNode* p=q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
                n--;
            }
            if(flag==1){
                reverse(temp.begin(),temp.end());
                flag=0;
            }
            else
                flag=1;
            res.push_back(temp);
        }
        return res;
    }
};
```