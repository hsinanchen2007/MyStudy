```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // 检验以A作为根结点的树是否包含树B
    bool RootAHasRootB(TreeNode * A, TreeNode * B) {
        
        if (B == NULL)  //一直找，直到B变为B树中的叶子节点的子节点才能return true
            return true;
        else if (A == NULL)
            return false;
        
        if (A->val != B->val)  // 值不相等，return false
            return false;
       
        return RootAHasRootB(A->left, B->left) && // 值相等，在左右子树中继续比较
             RootAHasRootB(A->right, B->right);
    }

public:
    //遍历二叉树，寻找与B根结点相等的节点，检验以该节点为跟的树树否包含树B
    bool isSubStructure(TreeNode* A, TreeNode* B) {
     
        if (A == NULL || B == NULL)        // A == NULL (递归终止条件，一直遍历到了叶节点的子节点NULL) 
            return false;                  // B== NULL (题目中说明 约定空树不是任意一个树的子结构)  

        if (A->val == B->val) {            // 找到了与B根结点相等的节点，将检验以该节点为跟的树是否包含树B
            if (RootAHasRootB(A, B))
                return true;
        }    
        return isSubStructure(A->left, B) ||   // 当前节点与B根结点不相等，将在左右子树中继续寻找
            isSubStructure(A->right, B);
    }
};
```