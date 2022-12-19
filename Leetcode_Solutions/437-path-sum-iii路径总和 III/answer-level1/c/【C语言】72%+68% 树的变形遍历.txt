### 解题思路
1.思路：
（1）按路径起始位置，遍历整棵树。
（2）从起始位置开始，将sum减去当前节点的值，剩下的值作为左右子树的sum，即sum = sum - root->val。递归调用findpath，由findpath返回左右子树满足sum要求的路径数。左右子树的路径数加上当前节点的路径树，即为当前节点路径数总和。
（3）依次递归遍历步骤（2）。
2.corner condition：
（1）.考虑到了的corner condition：
      A.起始位置不是根节点的路径；
      B.完全二叉树的路径；
（2）.没考虑到的：
      A.当一个路径满足了sum的条件要求，但左或右字数路径和为0时，这种情况没有计算进来；
3.知识点总结：
无特别的知识点。
4.耗时：>2h，花的时间太长了，哎~~。主要耗时点：
（1）算法设计，没有对负数节点情况考虑在内，导致算法设计时算法选择用偏了。-----读题不准；
（2）没有先设计corner condition，导致算法实现后corner condition适配花了很长时间------corner contition先设计再实现算法；
（3）起始点遍历和路径计算混成一个函数，算法逻辑不清晰------算法设计考虑不全；

后续一定要多读几遍题。mark~
![image.png](https://pic.leetcode-cn.com/1308721bd2a64510ab9f2d837e2d34ba241131858be57327b1b7dfec91766455-image.png)


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

 int findpath(struct TreeNode* root, int sum) {

    int leftc = 0;
    int rightc = 0;
    int retc = 0;
    if(root == NULL) {
        return retc;
    }

    if(root->val == sum) {
        retc = retc + 1;
        //printf("    find:match! node = %d, sum = %d\n", sum, sum);
        if(root->left != NULL) {
            leftc = findpath(root->left, sum - root->val);
        }

        if(root->right != NULL) {
            rightc = findpath(root->right, sum - root->val);
        }
        retc = retc + leftc + rightc;        
        return retc;
    }
    else {

        //printf("    find:node = %d, expectLorR = %d\n",root->val, (sum - root->val));
        if(root->left != NULL) {
            leftc = findpath(root->left, sum - root->val);
        }

        if(root->right != NULL) {
            rightc = findpath(root->right, sum - root->val);
        }
        //printf("    find:leftc = %d, rightc = %d\n", leftc, rightc);
        retc = retc + leftc + rightc;
    }
    return retc;
 }

int traveltree(struct TreeNode* root, int sum) {
    int leftc = 0;
    int rightc = 0;
    int retc = 0;
    int currc = 0;
    if(root == NULL) {
        return 0;
    }
    //printf("node = %d\n",root->val);
    currc = findpath(root, sum);
    //printf("curr = %d\n", currc);
    retc = retc + currc;

    leftc = traveltree(root->left, sum);
    rightc = traveltree(root->right, sum);
    retc = retc + leftc + rightc;
    return retc;
}

int pathSum(struct TreeNode* root, int sum){
    return traveltree(root, sum);
}
```