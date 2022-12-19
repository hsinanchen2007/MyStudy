# //前序遍历 迭代
构建一个栈，访问根节点，再访问左子树，当左子树遍历完后，访问右子树，此时返回父结点
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

```
#define MAX 1000
typedef struct Stack{
    struct TreeNode *p_TreeNode[MAX];        //我理解为是栈的结点，不对的大佬指正
    int p_Next;     //栈指针
}Stack;

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL){
        *returnSize=0;
        return NULL;
    }
    int *array_TreeNode = (int*)malloc(sizeof(int)*MAX);        //返回的数组
    int index_array = 0;      //数组的索引
    struct TreeNode *p = root;      //将二叉树赋给一个新的树
    Stack p_StackNode;      //构建一个栈结构，这里如果用struct的话会导致时间增多
    p_StackNode.p_Next = 0;       //初始化指针
    while(p != NULL || p_StackNode.p_Next != 0){
        while(p){       //如果树非空
            array_TreeNode[index_array++] = p->val;
            p_StackNode.p_TreeNode[(p_StackNode.p_Next)++] = p;       //将结点p存入栈
            p = p->left;
        }
        if(p_StackNode.p_Next != 0){
            p = p_StackNode.p_TreeNode[--(p_StackNode.p_Next)];     //返回到父结点
            p = p->right;
        }
    }
    *returnSize = index_array;
    return array_TreeNode;
}
```

# //前序遍历 递归

```
#define MAX 1000
void PreOrder(struct TreeNode* root, int* array, int* returnSize){
    if(root){
        array[(*returnSize)++] = root->val;
        PreOrder(root->left, array, returnSize);
        PreOrder(root->right, array, returnSize);
        }
    array[*returnSize]='\0';
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *array = (int*)malloc(sizeof(int) * MAX);
    PreOrder(root, array, returnSize);
    return array;
}
```
