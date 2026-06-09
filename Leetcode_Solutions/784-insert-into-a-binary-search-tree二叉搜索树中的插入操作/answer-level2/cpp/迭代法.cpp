### 解题思路
迭代法

### 代码

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* tmp = root;
        TreeNode* pre = root;
        while(tmp){
            if(tmp->val < val){
                pre = tmp;
                tmp = tmp->right;
            }else if (tmp->val > val){
                pre = tmp;
                tmp = tmp->left;
            }
        }
        TreeNode* node = new TreeNode(val);
        if (pre->val < val){
            pre->right = node;
        } else {
            pre->left = node;
        }
        return root;
    }
};
```