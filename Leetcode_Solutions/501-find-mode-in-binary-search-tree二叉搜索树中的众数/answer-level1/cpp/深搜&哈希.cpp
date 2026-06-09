### 解题思路
此处撰写解题思路

### 代码

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
    unordered_map<int,int> hash;
    
    vector<int> findMode(TreeNode* root) {
        pro(root);
        int maxL = INT_MIN;
        vector<int> res;
        for(auto it = hash.begin();it != hash.end();it++){
            if(it->second == maxL){
                res.push_back(it->first);
            }
            if(it->second > maxL){
                maxL = it->second;
                res.clear();
                res.push_back(it->first);
            }
        }
        return res;
    }

    void pro(TreeNode* root){
        if(!root) return;
        hash[root->val]++;
        if(root->left) pro(root->left);
        if(root->right) pro(root->right);
    }
};
```