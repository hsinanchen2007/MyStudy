### 判断一个Node是否是平衡二叉树，然后递归所有Node
包含两层递归，因此时间性能较差，但思路简洁易懂。
![image.png](https://pic.leetcode-cn.com/cbbafd9de18da7d3bf460525537cf8da9e3e4ad696a9206c0196bd2f30a930e4-image.png)

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
int max(int a, int b) {
    return a>b?a:b;
}

int height(struct TreeNode* node){

    if(node==NULL) return 0;
    int lh = 0, rh =0;
    if(node->left!=NULL) {
        lh = height(node->left);
    }
    if(node->right!=NULL) {
        rh = height(node->right);
    }
    if(abs(lh-rh>1)) return false;
    return max(lh, rh) + 1;
}

bool isBalanced(struct TreeNode* root){

    if(root==NULL) return true;  // 空树天然平衡
    
    bool flag1 = isBalanced(root->left);
    bool flag2 = isBalanced(root->right);    

    int leftTreeH = height(root->left);
    int rightTreeH = height(root->right);

    if(abs(leftTreeH - rightTreeH)>1||!flag1||!flag2) return false;

    return true;
}
```