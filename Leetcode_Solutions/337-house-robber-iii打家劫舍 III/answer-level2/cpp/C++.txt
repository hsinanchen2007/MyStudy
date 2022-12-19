对于每一个节点，都有l、r为其左右子结点的不带根节点的最大结果；而c则是该节点左右子结点的带根节点最大结果，同时也是其父节点的该子结点不带根节点最大结果。
返回值是该根节点下的最大结果。
```c++ []
class Solution {
public:
    int rob(TreeNode* root) {
        int temporaryVariable{};
        return func(root,temporaryVariable);
    }
private:
    int func(TreeNode* p,int& c){
        if(!p)
            return 0;
        int l{},r{};
        c=func(p->left,l)+func(p->right,r);
        return std::max(l+r+p->val,c);
    }
};
```
