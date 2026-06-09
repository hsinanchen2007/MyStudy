首先先判断空树，之后在判断当前节点是否就是那个子结构，不是就递归左右节点；
之后判断左右树是否就是有那个子结构（这个节点与子结构的头节点相同）注意此时若要判断的子结构为空的话需要
置为true



class Solution {
public:
    bool isSubStructure(TreeNode* a, TreeNode*b) 
    {
        if(a==NULL||b==NULL)
        return false;
        return issub(a,b)||isSubStructure(a->left,b)||isSubStructure(a->right,b);
    }
private:
    bool issub(TreeNode*a,TreeNode*b)
    {
        if(b==NULL)
        return true;
        if(a==NULL)
        return false;
        if(a->val!=b->val)
        return false;
        return issub(a->left,b->left)&&issub(a->right,b->right);
    }