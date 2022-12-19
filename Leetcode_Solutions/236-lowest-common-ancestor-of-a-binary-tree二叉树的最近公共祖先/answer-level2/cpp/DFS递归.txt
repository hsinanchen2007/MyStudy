首先想到的是用自顶向下的递归来做。
1. 顶部输入是：root，p，q；
2. 中间输入是：左右子树根结点，p，q;
3. 底层输入是：NULL，p，q。

递归的边界条件：
1. root为NULL时，到达树的最底部，直接返回NULL；
2. root为单个非NULL节点时（无左右孩子），判断root是否和p、q相等：
    1. 若等于p，返回p；
    2. 若等于q，返回q；
3. root为单个非NULL节点且存在非NULL左右孩子时，分别进入左右子树进行递归：
    1. Node* l = 递归（左孩子节点，p，q）；
    2. Node* r = 递归（右孩子节点，p，q）；
4. 根据l和r的值来判断每层的最近公共祖先：
    1. 若l和r均为非NULL，返回当前根结点root；
    2. 若l不为非NULL，返回l；
    3. 若r不为非NULL，返回r。

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        return dfs(root, p, q);
    }
    
    TreeNode* bfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 边界条件
        if(root == NULL) return NULL;
        if(root == p) return p;
        if(root == q) return q;
        
        TreeNode* l = dfs(root -> left, p, q); // 向左查
        TreeNode* r = dfs(root -> right, p, q); // 向右查
        
        // 当前子树的最近公共祖先判断
        if(l != NULL && r != NULL) return root;
        else if(l != NULL) return l;
        else return r;
    }
};
```
