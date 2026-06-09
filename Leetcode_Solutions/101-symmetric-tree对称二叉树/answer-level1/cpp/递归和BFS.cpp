### 解题思路
1.递归
```
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
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if (!root1 & !root2) {
            return true;
        }
        if (!root1 || !root2) {
            return false;
        }
        return (root1->val == root2->val)
            && isMirror(root1->left, root2->right)
            && isMirror(root1->right, root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
        
    }
};
```


2.BFS

### 代码

```cpp

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> v(cnt);
            for (int i = 0; i < cnt; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (!tmp) {
                    v[i] = INT_MIN;
                } else {
                    v[i] = tmp->val;
                    q.push(tmp->left);
                    q.push(tmp->right);
                }                
            }
            for (int i = 0; i < cnt/2; i++) {
                if (v[i] != v[cnt - i - 1]) {
                    return false;
                }
            }
        }
        return true;       
    }
};
```