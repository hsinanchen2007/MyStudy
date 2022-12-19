1. 递归

递归方法比较好理解，不再详细说明

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right) return root;
        return left ? left : right;
    }
};
```

2. 先求从根节点到每个 node 的路径，转化为链表首个公共节点问题（需要额外的存储空间）

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        // 获得从根节点到 p 节点的路径
        vector<TreeNode*> ppath;
        getPath(root, p, ppath);
        
        // 获得从根节点到 q 节点到路径
        vector<TreeNode*> qpath;
        getPath(root, q, qpath);
        
        int m = min(ppath.size(), qpath.size());
        if (m == 0) return NULL; // 这里考虑 p 或 q 不存在的情况
        // 找到最后一个公共节点
        for (int i=1; i<m; i++) {
            if(ppath[i] != qpath[i]) return ppath[i-1];
        }
        // 这里考虑 p 或 q 不存在的情况
        return ppath[m-1] == qpath[m-1] ? ppath[m-1] : NULL; 
    }
    
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(!root) return false;
        
        path.push_back(root);
        if(root == target) return true; // 找到节点，直接返回
        
        if(getPath(root->left, target, path)) return true; // 递归查找左子树
        if(getPath(root->right, target, path)) return true; // // 递归查找右子树
        
        path.pop_back(); // 如果左右子树都没找到，清理路径
        return false;
    }
};

```