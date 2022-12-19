### 解题思路
核心思路：预设一个函数isSame(A,B)，可以判断两个树是不是根节点相同且有共同结构，然后递归调用isSubStructure(A,B)
递归条件：B是A的子结构的充分条件：A isSame B 或 B是A的左（或右）子树的子结构
递归出口：A==NULL或B==NULL->返回false
执行用时 :60 ms, 在所有 C++ 提交中击败了43.85%的用户
内存消耗 :33.6 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    bool isSame(TreeNode*A,TreeNode*B){
        if(B==NULL){
            return true;
        }
        if(A==NULL||A->val!=B->val){
            return false;
        }
        return isSame(A->left,B->left)&&isSame(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL||B==NULL)return false; 
        return isSame(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
};
```