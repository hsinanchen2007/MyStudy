# 递归实现

要实现将一个二叉树翻转过来，可以将一整个二叉树看成只有三个节点的树，即根节点，左右子节点，那么只需要将左右子节点交换就可以了，然后对于每个子节点再次将其看成只有三个节点的树，将子节点的左右子节点交换，如此即可完成翻转，其实就是递归完成。
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
        {
            return NULL;
        }
        TreeNode* t;
        t = root->right;
        root->right = root->left;
        root->left = t;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```

# 迭代实现
迭代实现其实就是一个BFS的广搜，把模板套一下就好了，但是我卡在了条件判断上 惭愧。
如果给定的书是空树需要提前判断一下返回NULL
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* t;
        TreeNode* p;
        while(!que.empty())
        {
            p = que.front();
            que.pop();
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
                
            t = p->right;
            p->right = p->left;
            p->left = t;
        } 
        return root;
    }
};
```
