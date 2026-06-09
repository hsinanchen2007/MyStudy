### 【方案一】：深度优先搜索

```C++
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }

    void helper(TreeNode* root, int level, vector<int>& res) {
        if(root == NULL)
            return;
        
        if(level == res.size())
            res.push_back(root->val);
        else
            res[level] = max(res[level], root->val);
        
        helper(root->left, level+1, res);
        helper(root->right, level+1, res);
    }
};
```

### 【方案二】：广度优先搜索

```C++
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int curMax = INT_MIN;
            int size = q.size();

            for(int i=0; i<size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                curMax = max(curMax, node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            res.push_back(curMax);
        }

        return res;
    }
};
```
