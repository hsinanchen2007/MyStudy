### 解题思路
对树进行遍历，在遍历的过程中，比较A,B节点的值。

### 代码

```cpp
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==NULL) return false;
        if(A==NULL) return false;
        return traceTree(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool traceTree(TreeNode* A, TreeNode* B){
        if(B==NULL) return true;
        if(A==NULL) return false;
        if(A->val==B->val){
            return traceTree(A->left,B->left)&&traceTree(A->right,B->right);
        }
        return false;  
    }
   
};
```