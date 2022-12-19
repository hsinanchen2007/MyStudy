- DFS：
```
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        if (!root->left) { return 1 + minDepth(root->right); }
        if (!root->right) { return 1 + minDepth(root->left); }
        return min(minDepth(root->right),minDepth(root->left))+1;
    }
};
```
BFS：
```
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int min = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto cur = q.front();
                q.pop();
                if(!cur->left && !cur->right) return min + 1;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);           
            }
            min++;
        }
        return min;
    }
};
```
- 测试结果显示DFS（24ms）的平均用时要短于BFS（32ms）。