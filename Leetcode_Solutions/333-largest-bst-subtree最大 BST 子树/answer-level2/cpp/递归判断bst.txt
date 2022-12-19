### 解题思路
递归的对左右子树的值与根节点的值进行比较。左子树的值小于当前根节点的值，将当前根节点的值作为最大值传入左子树，左子树的值都小于他，递归处理；右子树的值都大于根节点的值，将根节点的值作为最小值传入右子树，右子树的值都大于他。

### 代码

```cpp
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(isValid(root, INT_MIN, INT_MAX)){
            return count(root);
        }
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }

    bool isValid(TreeNode* root, int min, int max){
        if(root == NULL){
            return true;
        }
        if(root->val <= min || root->val >= max){
            return false;
        }
        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
    }
    int count(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return count(root->left) + count(root->right) + 1;
    }
};

```