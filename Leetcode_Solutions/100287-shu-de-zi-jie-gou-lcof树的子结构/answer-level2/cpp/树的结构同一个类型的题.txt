### 解题思路
执行结果：时间99.35%， 空间100%
不管是匹配整棵树、整棵子树或是匹配相同的结构，都有同一个模板：主函数查找匹配起点，辅助函数用来判断是否符合题目要求的匹配。小心递归边界，需要认真分类讨论。

### 代码

```cpp
class Solution {
public:
    bool match(TreeNode* root, TreeNode* t){
        if(root){
            if(!t) return true;
            else if(root->val == t->val){
                return match(root->left, t->left) && match(root->right, t->right);
            }
            else return false;
        }
        else{
            if(t) return false;
            else return true;
        }
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) return false;
        return helper(A, B);
    }

    bool helper(TreeNode* A, TreeNode* B){
        if(A == nullptr && B == nullptr) return true;
        if(A == nullptr || B == nullptr) return false;
        bool eq1 = false, eq2 = false;
        if(A->val == B->val){
            if(match(A, B)){
                return true;
            }
            else{
                return helper(A->left, B) || helper(A->right, B);
            }
        }
        else return helper(A->left, B) || helper(A->right, B);
    }
};
```