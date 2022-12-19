C++
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;//结果
        if(root==NULL) 
            return res;
        
        queue<TreeNode*> q;//定义一个队列，用来放树
        q.push(root);//先把整棵树放进去
        while(!q.empty())
        {
            vector<int> temp;//临时变量
            int len = q.size();//队列的长度（队列中树的个数）
            for(int i=0;i<len;i++)
            {
                TreeNode* now = q.front();//获取队列的第一个
                q.pop();//队列弹出
                temp.push_back(now->val);//临时变量保存第一颗树的根节点
                if(now->left!=NULL) //左子树非空
                    q.push(now->left);
                if(now->right!=NULL)//右子树非空 
                    q.push(now->right);
            }
            res.insert(res.begin(), temp);//将临时变量保存到结果中(从前面插入)
        }
        return res;
    }
};
```