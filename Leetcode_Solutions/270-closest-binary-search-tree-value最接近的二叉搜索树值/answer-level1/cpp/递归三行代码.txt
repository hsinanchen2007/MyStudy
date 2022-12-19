

### 代码

```cpp
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if(root==NULL)return -1;
        if(target>root->val)return fabs(target-root->val)<fabs(target-closestValue(root->right,target))||!root->right?root->val:closestValue(root->right,target);
        else return fabs(target-root->val)<fabs(target-closestValue(root->left,target))||!root->left?root->val:closestValue(root->left,target);
    }
};
```