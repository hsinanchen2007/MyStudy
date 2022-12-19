
使用了堆栈，解题思路参考了浙江大学数据结构慕课的树的遍历一章


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct SNode* Stack;
struct SNode {
    struct TreeNode* Data;
    Stack Next;
};

Stack CreateStack(); //初始化堆栈
int IsEmpty(Stack S); //判断堆栈是否为空
void Push(Stack S, struct TreeNode* item); //入栈
struct TreeNode* Pop(Stack S); //出栈

//初始化堆栈
//构建一个堆栈的头结点，这个节点不代表任何一个堆栈中的元素，
//只是为了可以找到这个堆栈
Stack CreateStack() {
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

//判断是否为空
int IsEmpty(Stack S) {
    return (S->Next == NULL);
}

//入栈
void Push(Stack S, struct TreeNode* item) {
    Stack tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = item;
    //链栈栈顶元素是链表头结点，新入栈的链表在栈顶元素后面
    tmp->Next = S->Next;
    S->Next = tmp;
}

//出栈
struct TreeNode* Pop(Stack S) {
    Stack First;
    struct TreeNode* TopVal;
    if (IsEmpty(S)) {
        printf("堆栈空");
        return NULL;
    } else {
        First = S->Next; //出栈第一个元素在栈顶元素后面
        S->Next = First->Next; //把第一个元素从链栈删除
        TopVal = First->Data; //取出别删除节点的值
        free(First);
        return TopVal;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int i = 0; //用来存储树中元素的个数
    int *b = (int*)malloc(sizeof(int) * 1000);
    struct TreeNode* T = root;
    Stack S = CreateStack(); //创建并初始化堆栈S
    while (T || !IsEmpty(S)) {
        while (T) {
            Push(S, T); //压栈
            T = T->left; //遍历左子树
        }
        if (!IsEmpty(S)) { //堆栈不为空
            T = Pop(S); //出栈
            b[i++] = T->val; //读出节点的值
            T = T->right; //访问右节点
        }
    }
    *returnSize = i;
    return b;
}
```