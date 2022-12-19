### 解题思路
1.思路比较简单：递归 + 中序遍历。
2.corner condition：
无；
3.知识点总结：
递归+遍历，时间上比较吃亏，没办法。
4.耗时：30mins，比较满意哈哈 哈哈哈 O(∩_∩)O哈哈~。主要耗时点：
编码和特殊条件验证；
![image.png](https://pic.leetcode-cn.com/7a6c1e5914fc2553ddf9a9dad2a865e850feda07955743edeb5d469b7b8cddc8-image.png)


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


int sumEvenGrandparent(struct TreeNode* root){
    int ret = 0;
    if(root == NULL) {
        return ret;
    }

    if(root->val % 2 == 0) {
        if(root->left != NULL) {
            if(root->left->left != NULL) {
                ret = ret + root->left->left->val;
            }
            if(root->left->right != NULL) {
                ret = ret + root->left->right->val;
            }
        }

        if(root->right != NULL) {
            if(root->right->left != NULL) {
                ret = ret + root->right->left->val;
            }
            if(root->right->right != NULL) {
                ret = ret + root->right->right->val;
            }
        }        
    }
    ret = ret + sumEvenGrandparent(root->left);
    ret = ret + sumEvenGrandparent(root->right);    

    return ret;

}
```