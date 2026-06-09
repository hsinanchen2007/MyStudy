### 解题思路
此处撰写解题思路

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
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);//初始必为root
        while(!q.empty()){
            vector<int>r;
            int l=q.size();
            for(int i=0;i<l;i++){ //当前层节点都在队列中，依次取出
                TreeNode* t=q.front();//返回队首元素
                r.push_back(t->val);//放入数组r中
                q.pop();//弹出
                if(t->left)q.push(t->left); //将左右两边子树节点放入队列
                if(t->right)q.push(t->right);
            }
            res.push_back(r);//将层序遍历的一层放入二维数组中
        }
        return res;
    }
};


```