

```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q||!p){
            if(p == q) return true;
            else return false;
        }
        
        if(q->val != p->val) return false;
        
       return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};
```
   