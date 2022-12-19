### 解题思路
参考morries算法

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
    void flatten(TreeNode* root) {
        int i = 0;
        if(!root)
            return;
        TreeNode* cur = root;
        while(cur != nullptr){
            if(!cur->left)
                cur = cur->right;
            else{
                TreeNode* pre = _getPre(cur);
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
                cur = cur->right;
            }
        }
    }
private:
    TreeNode* _getPre(TreeNode* root){ //得到左子树前序遍历的最后一个节点
        TreeNode* pre = root->left;
        while(pre->right){
            pre = pre->right;
        }
        return pre;
    }
};
```