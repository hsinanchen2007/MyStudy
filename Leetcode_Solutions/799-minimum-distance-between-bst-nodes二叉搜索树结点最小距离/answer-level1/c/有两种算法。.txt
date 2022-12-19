### 解题思路
此处撰写解题思路
算法思想：
（1）	方法一：将树中所有节点的值写入数组，之后将数组排序。依次计算相邻数之间的差值，找出其中的最小值。
（2）	方法二：采用中序遍历，只需要遍历计算相邻数的差值，取其中最小值即可。
![image.png](https://pic.leetcode-cn.com/6e34460d2e68fc0144690364430adeeb2e6119d754833ab0af70f5bce1acb4b2-image.png)


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

int min;
struct TreeNode* pre;

int InOrder(struct TreeNode* root){
    if(root==NULL)  return 0;
    InOrder(root->left);
    if(pre!=NULL){
        if(min>root->val-pre->val){
            min = root->val-pre->val;
        }
    }
    pre = root;
    InOrder(root->right);
    return 0;
}

int minDiffInBST(struct TreeNode* root){
    min = 0x3f3f3f3f;
    pre = NULL;
    InOrder(root);
    return min;   
}
```