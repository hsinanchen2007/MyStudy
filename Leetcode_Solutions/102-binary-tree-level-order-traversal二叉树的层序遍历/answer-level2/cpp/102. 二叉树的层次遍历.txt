
使用BFS来解题
由于数据结构中没有深度，通过pair将深度和node绑定
最后结果还可以
```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res; 
        if(!root) return res;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 1));
        vector<int> curr;//当前vector，层序遍历所以当上一个vector完成后才会开始下一个
        while(!Q.empty())
        {
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if(depth>res.size()+1)
            {
                //保存、清空、换行
                res.push_back(curr);
                curr.clear();
            }
            curr.push_back(node->val);
            //新节点
            if(node->left) Q.push(make_pair(node->left, depth+1));
            if(node->right) Q.push(make_pair(node->right, depth+1));
        }
        res.push_back(curr);//push最后一行
        return res;
    }
};
```
