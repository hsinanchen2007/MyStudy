### 解题思路
加一个叶子结点判断就OK

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
        if(!root) return 0;
        queue<TreeNode*> q;
        TreeNode* p=root,*l=root;
        q.push(root);
        int high=0;
        while(!empty(q)){
            p=q.front();
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            if(!p->left&&!p->right) return high+1;
            if(p==l){
                high++;
                if(!empty(q)) 
                    l=q.back();
            }
        }
        return high;
    }
};
```