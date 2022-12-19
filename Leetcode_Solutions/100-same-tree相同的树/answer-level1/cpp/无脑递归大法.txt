```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( !p or !q ) return p == q;
        if ( p->val ==  q->val )
            return isSameTree( p->left, q->left ) and isSameTree( p->right, q->right );
        else
            return false;
    }
};
```
