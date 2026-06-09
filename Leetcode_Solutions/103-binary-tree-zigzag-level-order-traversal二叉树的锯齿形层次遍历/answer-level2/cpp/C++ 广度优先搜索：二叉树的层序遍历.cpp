### 解题思路
利用队列实现二叉树的层序遍历，在此基础上，对于偶数行反转行序列顺序
与102题基本一致

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
        //BFS
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        int x=0;  //判断当前行奇偶
        while(!q.empty()){
            int l=q.size();
            vector<int>tmp;
            for(int i=0;i<l;i++){
                TreeNode* t=q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            x++;
            if(x%2==0)reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};
```