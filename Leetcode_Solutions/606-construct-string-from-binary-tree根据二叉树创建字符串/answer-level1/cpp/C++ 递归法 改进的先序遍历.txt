### 解题思路
特别注意：左右子树为空时跳过，当仅左节点为NULL时加上空()，仅右节点为NULL时不加()，继续遍历。

### 代码

```cpp
class Solution {
public:
    void preOrderDFS(TreeNode* root, string& s) {
        s += "(";
        if(root){
            s += to_string(root->val);
            if(root->left || root->right) {
                preOrderDFS(root->left, s);
                if(root->right) preOrderDFS(root->right, s);
            }
        }
        s += ")";
    }
    string tree2str(TreeNode* t) {
        string res = "";
        if(!t) return res;
        res += to_string(t->val);
        if(t->left || t->right) {
            preOrderDFS(t->left, res);
            if(t->right) preOrderDFS(t->right, res);
        }
        return res;
    }
};
```