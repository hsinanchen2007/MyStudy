### 解题思路

思路很简单，如果 `新值比根节点val大，则新值插入到右子树；否则新值插入到左子树`。


### 代码1. 迭代

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* p = root;
        while(true){
            // 新值比根节点小，移动到左子树
            if(val < p->val){
                if(p->left) p = p->left;
                else{
                    p->left = new TreeNode(val);
                    break;
                }
            }
            // 新值比根节点大，移动到右子树
            if(val > p->val){
                if(p->right) p = p->right;
                else{
                    p->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
```

### 代码2. 递归版本
```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        root = insert(root, val);
        return root;
    }
private:
    TreeNode* insert(TreeNode* root, int& val){
        if(root == nullptr) return new TreeNode(val);
        if(val < root->val){
            root->left = insert(root->left, val);
        }else{
            root->right = insert(root->right,val);
        }
        return root;
    }
};
```