### 解题思路
其实考察的是二叉树的中序遍历的非递归方式，(递归也行，但是需要全遍历一遍，效率较低)
遍历到第k个(有相同值的话，遍历到第k小)
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> q;
        TreeNode* p = root;
        int last = INT_MIN;
        while(p || !q.empty()){
            while(p){
                q.push(p);
                p = p->left;
            }
            p = q.top();q.pop();//我这里还考虑了有相同值的情况，这题下所有值不相同
            if(p->val > last)
            {
                if(k == 1)
                    return p->val;
                else{
                    --k;
                    last = p->val;
                }
            }
            p = p->right;
        }
        return 0;
    }
};
```