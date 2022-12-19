### 解题思路
此处撰写解题思路
递归，判断两节点是否对称，注意：左节点的左侧和右节点的右侧比较是否相等，左节点的右侧和右节点的左侧比较是否相等
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //判断连个节点是否一样
bool isEqual(struct TreeNode* a, struct TreeNode* b){
    //都为空
    if (a == NULL && b == NULL) {
        return true;
    }
    //一个为空
    if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) {
        // printf("一个为空：%d %d\n", a->val, b->val);
        return false;
    }
    if (a->val == b->val) { 
        //这里注意是左右对称的，左节点的左侧和右节点的右侧比较
        bool left = isEqual(a->left, b->right);
        bool right = isEqual(a->right, b->left);

        if (left && right) {
            return true;
        } else {
            // printf("左右不等：%d %d\n", a->left->val, b->right->val);
            return false;
        }
    } else {
        // printf("节点值不同：%d %d", a->val, b->val);
        return false;
    }
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {
        return true;
    } else {
        return isEqual(root->left, root->right);
    }
}
```