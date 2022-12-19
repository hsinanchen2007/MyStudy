
* 先序遍历：根左右
* 循环条件为：栈不为空或者是p不为空，p是遍历指针
* 每当遇到非空二叉树时往左走。
* 当p为空时候(p没有左孩子或者左孩子已经被访问)，出栈元素是p的父节点，重新赋值为p，转而去遍历右子树

```c
#define SIZE 20000
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *node = (int *) malloc (sizeof(int) * 1000);
    *returnSize = 0;
    struct TreeNode* stack[SIZE];
    int top = -1;
    struct TreeNode* p = root;
    while (p || top > -1) {
        if(p) {
            stack[++top] = p;
            node[(*returnSize)++] = p -> val;
            p = p -> left;
        } else {
            p = stack[top--];
            p = p -> right;
        }
    }
    return node;
}

```