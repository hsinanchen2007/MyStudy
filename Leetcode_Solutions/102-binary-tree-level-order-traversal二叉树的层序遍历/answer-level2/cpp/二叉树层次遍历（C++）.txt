好多题都没有c++版本的题解，c++选手不要面子的吗。。。
本题仅给萌新提供一个参考答案，虽然我也是萌新，翻评论太麻烦了。

解法一：深度优先搜索（BFS）
```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        pre(root,0,res);
        return res;
    }
    void pre(TreeNode *root,int depth,vector<vector<int>> &res)
    {
        if(!root) return;
        if(depth>=res.size())   //说明需要增加一层
            res.push_back(vector<int>{});
        res[depth].push_back(root->val);
        pre(root->left,depth+1,res);
        pre(root->right,depth+1,res);
    }
};
```
解法二：广度优先搜索（BFS）
```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> nodes;
        if(root==nullptr)
            return res;
        queue<pair<TreeNode*,int>> que;
        int level=1;
        que.push(make_pair(root,level));
        while(!que.empty())
        {
            TreeNode* node=que.front().first;
            int lev=que.front().second;
            que.pop();
            if(lev==level)
            {
                nodes.push_back(node->val);
            }
            else
            {
                res.push_back(nodes);
                nodes.clear();
                nodes.push_back(node->val);
                level++;
            }
            if(node->left!=nullptr)
                que.push(make_pair(node->left,lev+1));
            if(node->right!=nullptr)
                que.push(make_pair(node->right,lev+1));
        }
        res.push_back(nodes);
        return res;
    }
};
```
解法二虽然能通过，但是感觉太冗余了，看看就好，水平有限。