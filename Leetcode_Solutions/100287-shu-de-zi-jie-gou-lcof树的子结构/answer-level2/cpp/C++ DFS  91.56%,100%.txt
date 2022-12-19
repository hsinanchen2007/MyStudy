## 本来想用BFS,但看到DFS结果不错而且DFS更简短就不用了
```
class Solution {
public:
    bool isSubStructure(TreeNode*& p, TreeNode*& q) {
        if(!p || !q) return 0;      // 两棵树在DFS的时候都不能是空树
        if(p->val==q->val)          // 由于题目给的二叉树节点值不会重复,可以直接判断+返回
            return tree_match(p,q);
        return isSubStructure(p->left,q) || isSubStructure(p->right,q);   // dfs查找
    }
    bool tree_match(TreeNode*& p,TreeNode*& q){
        if(!q) return 1;            // 若q已经没有节点了,就说明q的一支已经遍历完成且全部匹配
        if(p && p->val==q->val)     // 节点相等,用dfs判断左右节点的相等状况
            if(tree_match(p->left,q->left)&&tree_match(p->right,q->right))
                return 1;
        return 0;           // 以上条件均不满足则不匹配
    }
};
```
