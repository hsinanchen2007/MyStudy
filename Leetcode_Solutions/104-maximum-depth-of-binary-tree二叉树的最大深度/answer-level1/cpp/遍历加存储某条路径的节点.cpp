### 解题思路
遍历加存储某条路径的节点
不存储也可以。计算长度就好了。
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
    void md(TreeNode* root, vector<int> &v, int &maxd){
        if(!root) return;
        v.push_back(root->val);
        //cout<<root->val<<" ";
        if(!root->left && !root->right) {
            if(maxd<v.size()){
                maxd = v.size();
            }
        }
        md(root->left, v, maxd);
        md(root->right, v, maxd);
        v.pop_back();

    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxd=0;
        vector<int> v;
        md(root, v, maxd);
        return maxd;
    }
};
```