```
typedef struct TreeNode TreeNode; 
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    TreeNode *stack[30];
    int *res = (int *)malloc(100 * sizeof(int));  //此处不能复制为NULL，不然影响右子树为NULL的节点判断
    int size = 0;
    int arrSize = 0;
    TreeNode *q = (TreeNode *)malloc(sizeof(TreeNode));
    stack[size++] = root;
    while(size != 0) {
        TreeNode *p = stack[size - 1];
        while (p->left != NULL && q != p->left && q != p->right) { //上一个返回的节点不能是其左右子树才能再进行左子树压栈
            stack[size++] = p->left;
            p = p->left;
        }
        if (p->right != NULL && p->right != q) {
            stack[size++] = p->right;
        } else {
            res[arrSize++] = p->val;
            q = p;
            size--;
        }
    }
    *returnSize = arrSize;
    return res;
}
```
![image.png](https://pic.leetcode-cn.com/2751380335f8bb8258b575a8d3a6c46474d6ea27de063741af21c8d1e030160b-image.png)
