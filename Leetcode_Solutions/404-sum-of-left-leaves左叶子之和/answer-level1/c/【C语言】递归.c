### 解题思路
思路：递归遍历二叉树，通过（root->left->left == NULL && root->left->right == NULL）的条件来判断一个节点是否是左叶子节点，然后递归求和。
做题耗时：24mins。
心得：由于审题不仔细，看成是把所有左节点求和，因此第一版实现的时候把各个左根节点也相加了。在比赛或者考试时，由于没有练习时那么多提示，因此，更难通过。后续还得注意审题。
![image.png](https://pic.leetcode-cn.com/bdf15a8eaddda69bf2495429e187c91549687f1be828001bd1a12868ab4a5d5c-image.png)


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

int sumOfLeftLeaves(struct TreeNode* root){
    int sum = 0;
    if(root == NULL) {
        return sum;
    }
   
    if (root->left != NULL) {
        if(root->left->left == NULL && root->left->right == NULL) {
            sum = sum + root->left->val;
        }
        else {
            sum = sum + sumOfLeftLeaves(root->left);
        }        
    }

    if (root->right != NULL) {
        sum = sum + sumOfLeftLeaves(root->right);
    }   
    
    return sum;   
}
```