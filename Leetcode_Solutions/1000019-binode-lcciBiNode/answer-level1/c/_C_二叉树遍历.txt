### 解题思路
本题要求原地，使用二叉树遍历及链表插入即可，思路如下：
先left/right进行遍历，得到叶子节点时需要记录，为此次的头节点；
左节点的地址可能为此次链表的头，右节点的直接插入（因二叉搜索树，右节点的值大），此题自己画个图比较好理解
直接上代码
![123.PNG](https://pic.leetcode-cn.com/4e8b0d53fd1e56910f42f324632a2fb5563d6a9a35b175da83823b12710454af-123.PNG)


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


struct TreeNode* convertBiNode(struct TreeNode* root){
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode *ret1;
    struct TreeNode *ret2;
    struct TreeNode *ret = NULL;
    ret1 = convertBiNode(root->left);
    if (ret1 != NULL) {
        ret = ret1;
        while (ret1->right != NULL) { // ret is the head, find the tail
            ret1 = ret1->right;
        }
        ret1->left = NULL;
        ret1->right = root; // insert
    }
    ret2 = convertBiNode(root->right);
    root->left = NULL;
    root->right = ret2;
    if (ret == NULL) {
        return root;
    }
    return ret;
}
```