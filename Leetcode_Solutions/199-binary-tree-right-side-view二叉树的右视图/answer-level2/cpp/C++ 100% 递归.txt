思路：自定义遍历顺序：根->右->左

递归：
![image.png](https://pic.leetcode-cn.com/ded6e193462dccd31cbe8e2adc355f5f124a72b039be38d3cecdd29fa4c314c9-image.png)

```cpp
    // 思路：自定义遍历顺序：根->右->左
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        util(res,root,1);
        return res;
    }
    
    void util(vector<int> &res, TreeNode*root, int n) {
        if (!root) return;
        if (res.size()<n) res.push_back(root->val);
        util(res,root->right,n+1);
        util(res,root->left,n+1);
    }
```

非递归：
```cpp
    // 思路：自定义遍历顺序：根->右->左
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()){
            int n = qu.size();
            bool saved = false;
            for (int i =0; i< n;i++) {
                TreeNode* node = qu.front();  
                qu.pop();
                if (!saved && node) {
                    res.push_back(node->val);
                    saved = true;
                }
                if (node->right) qu.push(node->right);
                if (node->left) qu.push(node->left);
            }
        }
        // util(res,root,1);
        return res;
    }
```

