### 解题思路
先比较头节点是不是相同：
1、如果头节点相同，调用compare函数比较子节点（可能子节点还有子节点）是否相同。
2、如果头节点不相同，分别调用A的左/右子节点重新进入判定函数。
compare函数：把每个节点当作头节点，比较AB是不是一样的，如果不是，返回false进入2.如果一样，调用AB左右节点再次比较。
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
        if(A==nullptr||B==nullptr) return false;
        bool result=false;
        if(A->val==B->val) //头节点相等
            result=compare(A,B);//比较子节点
        if(result==false)//头节点不相等或者头节点相等但是子节点不相等
            result=isSubStructure(A->left,B)||isSubStructure(A->right,B);
        return result;
    }

    bool compare(TreeNode* A,TreeNode* B)//比较子节点
    {
        if(B==nullptr) return true;
        if(A==nullptr) return false;
        if(A->val!=B->val && A->val!=B->val)
            return false;//子节点不相等
        else//节点相等
            return compare(A->left,B->left)&&compare(A->right,B->right);
    }
};
```