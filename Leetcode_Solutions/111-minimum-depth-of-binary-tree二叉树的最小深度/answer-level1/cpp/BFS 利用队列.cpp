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
    int minDepth(TreeNode* root) {
        if(root == NULL)  return 0;
        queue<TreeNode*> q;
        TreeNode* p = root;
        q.push(p);
        int minh = 0;
        while(p || !q.empty()) {
            minh += 1;
            int wide = q.size();
            for(int i = 0 ; i < wide ; i ++) {
                p = q.front();
                q.pop();
                if(p -> left == NULL && p -> right == NULL) {
                    return minh;
                }
                if(p -> left)  q.push(p -> left);
                if(p -> right)  q.push(p -> right);
            }
        }
        return minh;
    }
};
```