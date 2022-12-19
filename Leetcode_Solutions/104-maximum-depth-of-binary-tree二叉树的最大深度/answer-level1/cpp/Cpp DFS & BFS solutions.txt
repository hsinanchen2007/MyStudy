**DFS:**
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};
```
- Time: O(N)
- Space: O(h) (树的深度H)

**BFS:**
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()) {
            int s = q.size();
            for(int i = 0; i < s; ++i) {
                TreeNode* t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            depth++;
        }
        return depth;
    }
};
```
- Time: O(N)
- Space: O(w) (树每一层的宽度W)

#
- 来自LeetCode英文网站：insomniacat用户