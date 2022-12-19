### 解题思路
isSubStructure函数的功能是先遍历A树的每一个节点都作为根节点和B树比较
创建辅助函数hasSubStructure来判断两棵树是否相等
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==NULL || A==NULL)  return false;//A或B为空 false
        //遍历A树结点
        return hasSubStructure(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
    
    //用来比较两棵树  
    bool hasSubStructure(TreeNode* A, TreeNode* B)
        {    
            if(A==NULL && B==NULL)//A、B均为空，true;
                return true;
            if(B == NULL)//A不为空，B为空，说明前面的结点都对应  true
                return true;          
            if(A == NULL)//A为空，B不为空，说明还有不对应的 false
                return false;
            if(A->val != B->val) //A、B结点都不相等 false
                return false;
            if(A->val == B->val) //AB结点相等，继续比较
                return hasSubStructure(A->left,B->left) && hasSubStructure(A->right,B->right);
            return false;
        }
};
```