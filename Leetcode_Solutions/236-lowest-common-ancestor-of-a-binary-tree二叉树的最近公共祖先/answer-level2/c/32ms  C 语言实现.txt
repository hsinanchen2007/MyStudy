### 3 种情况：

第一种情况：左子树和右子树均找没有p结点或者q结点；（这里特别需要注意，虽然题目上说了 p 结点和 q 结点必定都存在，但是递归的时候必须把所有情况都考虑进去，因为题目给的条件是针对于整棵树，而递归会到局部，不一定都满足整体条件）

第二种情况：左子树上能找到，但是右子树上找不到，此时就应当直接返回左子树的查找结果；

第三种情况：右子树上能找到，但是左子树上找不到，此时就应当直接返回右子树的查找结果；

第四种情况：左右子树上均能找到，说明此时的p结点和q结点分居root结点两侧，此时就应当直接返回 root 结点

```c
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
        if(root==p||root==q||!root)return root;
        
        struct TreeNode* left=lowestCommonAncestor(root->left,  p, q);
        struct TreeNode* right=lowestCommonAncestor(root->right,  p, q);
        
        if(!left&&!right)return NULL;
        else if(left&&!right)return left;
        else if(right&&!left)return right;
          
        return root;
    }
```