思路很简单：
1. 先遍历，把每个节点存起来并记录好坐标
2. 多标尺排序：列小优先、行大优先、值小优先
3. 存到答案里

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
class Solution {
public:
    struct node
    {
        node(int v, int xx, int yy) : val(v), x(xx), y(yy) {}
        int val;
        int x;
        int y;
    };

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<node> vec;
        dfs(root, vec, 0, 0);

        auto cmp = [](node a, node b)
        {
            if(a.x != b.x) return a.x < b.x;
            else if(a.y != b.y) return a.y > b.y;
            return a.val < b.val;
        };
        sort(vec.begin(), vec.end(), cmp);
    
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(vec[0].val);
        int pre = vec[0].x;
        for(int i = 1; i < vec.size(); i++)
        {
            if(vec[i].x != pre)
            {
                ans.push_back(cur);
                cur.clear();
                pre = vec[i].x;
            }
            cur.push_back(vec[i].val);
        }
        
        if(!cur.empty()) ans.push_back(cur);

        return ans;
    }

    void dfs(TreeNode* root, vector<node>& vec, int x, int y)
    {
        if(root == nullptr) return;
        vec.push_back(node(root->val, x, y));

        dfs(root->left, vec, x - 1, y - 1);
        dfs(root->right, vec, x + 1, y - 1);
    }
};
```
