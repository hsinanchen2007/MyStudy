### 解题思路


### 代码

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
public:
    bool isSubStructure2(TreeNode *A, TreeNode *B)
    {
        //递归判断A和B的结构是否完全相同！
        if(!A || !B)
        {
            if(!B)
                return true;  //B为空，递归完毕
            else
                return false;  //B不为空但A为空，失败
        }
        if(A->val != B->val)return false;  //当前A，B节点值不相同
        //运行到这说明当前节点值相同
        //接下来递归判断左右子树结构都要相同
        return isSubStructure2(A->left, B->left) && isSubStructure2(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B)return false;  //空树不是任意一个树的子结构
        //isSubStructure2(A, B)：假设A能作为B的根节点，判断A和B的结构是否完全相同
        //isSubStructure(A->left, B)：假设A->left能作为B的根节点
        //isSubStructure(A->right, B)：假设A->right能作为B的根节点
        return isSubStructure2(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
```