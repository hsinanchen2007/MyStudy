### 解题思路
很有意思的深搜索题；
分三种情况讨论，
第一种不是叶节点，继续遍历；
第二种是叶节点，值不为零，返回本身；
第三种是叶节点，值为零，返回空指针，赋值给上一节点就行

### 代码

```cpp
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root){
        if(!root) {
            return nullptr;
        }
        (*root).left = pruneTree(root->left);
        (*root).right = pruneTree(root->right);
        if(!root->left && !root->right && !root->val) {
            return nullptr;
        }
        return root;
   }
};
```