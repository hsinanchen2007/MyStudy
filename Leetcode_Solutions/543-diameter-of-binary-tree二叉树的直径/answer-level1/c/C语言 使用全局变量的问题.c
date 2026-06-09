### 解题思路
![image.png](https://pic.leetcode-cn.com/4c30bf649629167ae545f99b3726e2a015caa0e4e163e125731a3e0cccc16012-image.png)
主要是为了解释全局变量`res`在使用的过程中为何要在函数内重复赋值的问题：
怀疑是力扣测试时多次调用入口函数导致全局变量`res`被累加，故重新赋值为0使得每次被重新调用的时候不出错。
*在leetcode中测试不对全局变量重新赋值也可成功提交*

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
#define max(a,b) ( ((a)>(b)) ? (a):(b) )

int res = 0;
int maxDepth(struct TreeNode* root);
int diameterOfBinaryTree(struct TreeNode* root){
    //注意：最大路径长度不一定全都穿过根节点
    //C语言中不能传引用
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) return 0;
    else{
        res = 0;
        maxDepth(root);
        return res;
    }
}

int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    else if(root -> left == NULL && root -> right == NULL) return 1;
    else {
        int lheight = maxDepth(root -> left);
        int rheight = maxDepth(root -> right);
        //res = res > (lheight + rheight) ? res : (lheight + rheight);
        res = max(res,(lheight + rheight));
        return max(lheight, rheight) + 1;
    }
}
    
```