很直接的思路：若该节点需要被删除，则将左右子树结点存入 res 中。若 res 中也存在被删除的结点，那么将其 erase。注意一开始需要先将 root 置入 res。
```c++
class Solution {
private:
    vector<TreeNode*> res;
    map<TreeNode*, TreeNode*> pa;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        parent(root, NULL);    // 存父节点
        res.push_back(root);  //一开始需要先将 root 置入 res
        dfs(root, to_delete);        
        return res;
    }

    void parent(TreeNode *root, TreeNode *p)
    {
        if (!root) return;
        pa[root] = p;
        parent(root -> left, root);
        parent(root -> right, root);
    }

    void dfs(TreeNode *root, vector<int> &to_delete)
    {
        if (!root) return;
        if (find(to_delete.begin(), to_delete.end(), root -> val) != to_delete.end())  
        {
            if (root -> left) res.push_back(root -> left);  // 若左右子树非空，置入 res
            if (root -> right) res.push_back(root -> right);
            dfs(root -> left, to_delete);   // 递归删除
            dfs(root -> right, to_delete); 
            root -> left = NULL;    // 把要删除结点的左右子树设为 NULL
            root -> right = NULL;
            if (pa[root] && pa[root] -> left == root) pa[root] -> left = NULL;  // 父节点的对应 left 或 right 指针也要设 NULL
            if (pa[root] && pa[root] -> right == root) pa[root] -> right = NULL;
            auto it = find(res.begin(), res.end(), root);  // 若待删结点之前被加入 res，则将其删除
            if (it != res.end()) res.erase(it, it + 1);
        }
        else
        {
            dfs(root -> left, to_delete);
            dfs(root -> right, to_delete);
        }
    }
};
```