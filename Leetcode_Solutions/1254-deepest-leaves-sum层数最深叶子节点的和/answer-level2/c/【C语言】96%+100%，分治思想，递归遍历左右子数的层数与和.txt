### 解题思路
1.思路：
（1）分治思想，利用递归方法，分别取左子树和右子树最深叶子节点的层数，然后左右比较。如果有一边层数更深，那么久放弃浅的那一边，如果两边相等，则将左右两边叶子节点之和再求和。
（2）各子树在进行层数遍历的同时，也同时可以求得各子树的最深叶子节点之和。
2.corner condition：
（1）.当只有一个节点时。这个corner condition一开始就想到了，所以对左右子树操作时，先进行判空，这不仅使corner condition考虑充分了，而且也避免了稳定性问题；
3.经验教训：
（1）在计算左右子树的深度时，将左右子树的深度加起来作为当前根节点的深度，这是个错误，且这种错误不容易排查。因此，编码时还是要精力非常集中才行，保证编码时思路的清晰才能保证最终实现的准确。
（2）使用递归时，对一次性编码正确要求更高，因为递归的话，排错比一般算法更困难。
（3）由于自己一直从事嵌入式开发的原因，对内存消耗非常敏感，所以在做任何题的时候，都不由自主的对内存占用非常吝啬，在一些细小的数据结构上也想用动态内存分配。在算法选择时不自然的选择递归等高耗时算法。leetcode和竞赛题对时间要求比较高，后续要努力改变这种习惯:在细小数据结构上，适当的消耗一些内存，不用将精力过多的放在动态内存分配的设计上。对于递归算法，尽量使用偏内存消耗的动态规划算法来实现。
4.耗时：40mins，解题时间算比较少了。主要原因：
（1）corner condition在编码时就考虑比较全面，避免了后期排错耗时；
（2）算法实现时细节已经比较清晰，避免了后期排错；
这题做得比较顺，mark一下~~~~~~~

![image.png](https://pic.leetcode-cn.com/416623ecfa7ae846a53532ca7228b2f4cc0c978e15b1e8ae2f82f44f3a6a9c10-image.png)


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

#define SUMMAX 10000

int sumfunc(int *a, int size) {
    int ret = 0;
    int i = 0;
    while(i < size) {
        ret = ret + a[i];
        i++;
    }
    return ret;
}

int getdeep(struct TreeNode *root, int *sum) {
    int deep = 0;
    int lsum = 0;
    int rsum = 0;
    int ldeep = 0;
    int rdeep = 0;
    if(root->left == NULL && root->right == NULL) {
        deep = 1;
        *sum = root->val;
        return deep;
    }
    else if(root->left != NULL && root->right == NULL) {
        deep = 1 + getdeep(root->left, &lsum);
        *sum = lsum;
    }
    else if(root->left == NULL && root->right != NULL) {
        deep = 1 + getdeep(root->right, &rsum);
        *sum = rsum;
    }
    else if(root->left != NULL && root->right != NULL) {
        ldeep = getdeep(root->left, &lsum);
        rdeep = getdeep(root->right, &rsum);
        //printf("root-val = %d, ldeep = %d, rdeep = %d\n",root->val, ldeep, rdeep);
        if(ldeep > rdeep) {
            deep = 1 + ldeep;
            *sum = lsum;
        }
        else if (ldeep < rdeep) {
            deep =1 + rdeep;
            *sum = rsum;
        }
        else if (ldeep == rdeep) {
            deep = 1 + ldeep;
            *sum = lsum + rsum;
        }
    }
    return deep;
}

int deepestLeavesSum(struct TreeNode* root){
    int total = 0;
    int ldeep = 0;
    int lsum = 0;
    int rdeep  = 0;
    int rsum = 0;
    if(root->left == NULL && root->right == NULL) {
        total = root->val;
        return total;
    }
    else if(root->left != NULL && root->right == NULL) {
        ldeep = getdeep(root->left, &lsum);
        total = lsum; 
    }
    else if(root->left == NULL && root->right != NULL) {
        rdeep = getdeep(root->right, &rsum);
        total = rsum;
    }else if(root->left != NULL && root->right != NULL) {
        ldeep = getdeep(root->left, &lsum);
        rdeep = getdeep(root->right, &rsum);
        //printf("ldeep = %d, rdeep = %d\n", ldeep, rdeep);
        if(ldeep < rdeep) {
            total = rsum;
        }
        else if (ldeep > rdeep) {
            total = lsum;
        }
        else if(ldeep == rdeep) {
            total = lsum + rsum;
        }        
    }
    
    return total;

}
```