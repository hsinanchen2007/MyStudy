直观的思路是BFS，具体实现层面则各有千秋。

似乎，大家都喜欢把代码写的“越短越好”。真的这样吗？

既然复杂度固定在这里了，与其死磕“怎样缩短代码”，不如写的直白一点，更接近high-level思考的方式：

每层的节点，放到每层对应的vector中。怎样获得每层对应的vector？通过维护每个节点的depth，相同depth的节点获得相同的vector。

自定义一个数据结构Info，把node和depth包装到一起，视为“增强版的节点”数据结构。

```C++
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> v_empty;

        struct Info {
            TreeNode* node;
            int depth;
        };

        queue<Info> q;
        Info info;
        info.node = root;
        info.depth = 0;
        q.push(info);

        while(!q.empty()) {
            info = q.front();
            q.pop();

            // root
            if (info.node==NULL) {
                continue;
            }

            //vector<int>& v = res[info.depth];
            if(info.depth==res.size()) {
                res.push_back(v_empty);
            }
            vector<int>& v = res[info.depth];
            v.push_back(info.node->val);

            // left & right
            Info new_info;

            new_info.node = info.node->left;
            new_info.depth = info.depth + 1;
            q.push(new_info);

            new_info.node = info.node->right;
            new_info.depth = info.depth + 1;
            q.push(new_info);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
```
