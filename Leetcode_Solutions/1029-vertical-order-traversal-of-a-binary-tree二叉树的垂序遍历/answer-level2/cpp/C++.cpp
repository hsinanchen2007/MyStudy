```
遍历一遍完了以后得到:
map<int, vector<pair<int, int>> 
存储的结构.
后按照指定排序规则, 对map当中的每个元素按按照特定的排序方式进行输出即可
第一个int 为x
第二个int 为y, 我使用向下递增的形式
第三个int 为node->val
```

```
class Solution 
{
public:
    typedef map<int, vector<pair<int, int>>>  TT;
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        TT t;
        vector<vector<int>> ans;
        dfs(root, 0, 0, t);
        
        for(auto &p : t)
        {
            vector<int> temp;
            sort(p.second.begin(), p.second.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
                return (lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second);
            });
            for(int i = 0; i != p.second.size(); ++i)
                temp.push_back(p.second[i].second);
            ans.push_back(temp);
        }
        return ans;
    }
    //x, y 代表当前节点的坐标
    void dfs(TreeNode *node, int x, int y, TT &t)
    {
        if(node)
        {
            t[x].push_back({y, node->val});
            dfs(node->left, x - 1, y + 1, t);
            dfs(node->right, x + 1, y + 1, t);
        }
    }
};
```

```
执行用时 : 8 ms, 在Vertical Order Traversal of a Binary Tree的C++提交中击败了100.00% 的用户
内存消耗 : 14.7 MB, 在Vertical Order Traversal of a Binary Tree的C++提交中击败了39.62% 的用户
```