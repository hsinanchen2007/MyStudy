1. straight forward的解法

反复从根开始遍历， 把叶子节点加入结果集中，并删除叶子节点， 直到只剩下根节点为止。最后把根加入结果集。

```cpp
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        while(!(root->left == nullptr && root->right == nullptr)){
            vector<int> leaves;
            dfs(root, leaves);
            res.push_back(leaves);
        }
        res.push_back({root->val});
        return res;
    }
    void dfs(TreeNode* root, vector<int> & leaves){
        if(root->left != nullptr){
            if(root->left->left == nullptr && root->left->right == nullptr){
                leaves.push_back(root->left->val);
                delete root->left;
                root->left = nullptr;
            }
        }
        if(root->right != nullptr){
            if(root->right->left == nullptr && root->right->right == nullptr){
                leaves.push_back(root->right->val);
                delete root->right;
                root->right = nullptr;
            }
        }
        if(root->left != nullptr) dfs(root->left, leaves);
        if(root->right != nullptr) dfs(root->right, leaves);
    }
};
```

2. 肯定有比第一种方法更快的解法。
那么我们采取后续遍历，把叶子节点作为计算高度的起点，使用一个map， key就是结点的高度，
把相同高度的节点放在一起， 拷贝进结果集中。


```cpp
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<int, vector<int>> m;
        dfs(root, m);
        vector<vector<int>> res;
        for(auto & p : m){
            res.push_back(p.second);
        }
        return res;
    }
    int dfs(TreeNode* root, map<int, vector<int>> & m){
        if(root == nullptr) return 0;
        int l = dfs(root->left, m);
        int r = dfs(root->right, m);
        int h = max(l, r) + 1;
        m[h].push_back(root->val);
        return h;
    }
};
```

3. 更近一步， 我们可以省略map, 直接把结果放进vector<vector<int>>中。
需要注意的是， vector的下标为height-1; 而且需要时时resize vector

```cpp
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, vector<vector<int>> & res){
        if(root == nullptr) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        int h = max(l, r) + 1;
        if(res.size() < h) res.resize(h);
        res[h-1].push_back(root->val);
        return h;
    }
};
```