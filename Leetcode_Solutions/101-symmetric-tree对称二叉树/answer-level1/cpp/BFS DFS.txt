### 解题思路
BFS DFS

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


 //BFS


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int qsize = q.size();
            for(int i = 0; i < qsize; i++){
                root = q.front(); q.pop();
                if(root){q.push(root->left);q.push(root->right);v.push_back(root->val);}
                else v.push_back(INT_MIN);
            }
            for(int i = 0; i < v.size()/2; i++){
                if(v[i] != v[v.size()-1-i])return false;
            }
        }
        return true;
    }
};

//DFS

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return DFS(root->left, root->right);
    }
private:
    bool DFS(TreeNode* leftnode, TreeNode* rightnode){
        if(!leftnode || !rightnode) return !leftnode && !rightnode;
        else if(leftnode->val != rightnode->val) return false;
        else return DFS(leftnode->left, rightnode->right) && DFS(leftnode->right, rightnode->left);
    }
};
```