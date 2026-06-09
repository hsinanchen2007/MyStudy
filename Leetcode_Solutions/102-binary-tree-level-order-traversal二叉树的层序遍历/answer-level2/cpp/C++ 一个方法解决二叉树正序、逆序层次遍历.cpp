### 解题思路
使用一个map来保存每层元素

### 正序，从上到下

```cpp
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        f(root, 0);
        vector<vector<int>> res;
        for(auto v : map1) {
            res.push_back(v.second);
        }

        return res;
    }


    void f(TreeNode* root,  int level) {
        if(root == NULL)
            return;
        map1[level].push_back(root->val);
        f(root->left, level+1);
        f(root->right, level+1);

    }
    map<int, vector<int>> map1;
};
```

### 逆序 从下到上

```cpp
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
        f(root, 0);
        vector<vector<int>> res;

        for(int i = map1.size()-1; i >= 0; i--) {
            res.push_back(map1[i]);
        }
        return res;
    }

    void f(TreeNode* root,  int level) {
        if(root == NULL)
            return;
        map1[level].push_back(root->val);
        f(root->left, level+1);
        f(root->right, level+1);

    }
    map<int, vector<int>> map1;
};
```