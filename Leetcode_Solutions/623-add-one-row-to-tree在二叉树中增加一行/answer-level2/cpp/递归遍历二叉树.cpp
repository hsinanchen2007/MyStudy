// ![结果.png](https://pic.leetcode-cn.com/2a45511ca857a49631e8758985094eea419d1e2f9c7da4f4faf4300cc595418e-%E7%BB%93%E6%9E%9C.png)

// 对于d为1进行特殊处理，其他情况则从根节点向下遍历，记录当前的层数，层数需要从2开始，每遍历一层，层数加一。当层数和d相同时意味着需要在此处进行插入节点。新建两个节点，判断原有节点左右子树的情况，如果有左孩子，则将左孩子连接到新的左孩子的左边；若有右孩子，则将右孩子连接到新的右孩子的右边。完成这个操作之后再把新建立的左右孩子和根节点进行连接。👌

// 需要注意插入节点时一定是成对插入的。

// ```cpp
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* tmp = new TreeNode(v);
            tmp->left = root;
            root = tmp;   
        }
        else{
            //从第二层开始判断
            helper(root, v, d, 2);
        }
        return root;
    }
    void helper(TreeNode* root, int v, int d, int l){
        //l表示层数
        if(l == d){
            TreeNode* tmp1 = new TreeNode(v);
            TreeNode* tmp2 = new TreeNode(v);
            if(root -> left){
                tmp1 -> left = root -> left;
            }
            if(root -> right){
                tmp2 -> right = root -> right;
            }
            root -> left = tmp1;
            root -> right = tmp2;
            //return  ;
        }
        else{
            if(root -> left)
                helper(root->left, v, d, l+1);
            if(root -> right)
                helper(root->right, v, d, l+1);
        }
        return ;
    }
};
// ```
