非递归中序遍历，每遍历一个元素，令 k--，k == 0 时立即返回

```
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* p = root;
            
        while(p || !s.empty()){
            while(p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();

            k--;
            if(k == 0) return p->val;

            p = p->right;
        }
        
        return p->val;
    }
};
```
