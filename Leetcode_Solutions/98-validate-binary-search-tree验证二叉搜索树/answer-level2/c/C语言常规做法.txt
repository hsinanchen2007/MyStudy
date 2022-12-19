通过中序遍历即可判断，核心部分代码基本上从[二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/cyu-yan-chang-gui-zuo-fa-by-bevischou-108/)照搬。为了简明易读，部分代码写成函数。

- 版本二
版本一中只需要记录上一个节点val值。但版本二的运行时间和内存还是很不理想。
```c
typedef struct TreeNode treeNode;

typedef struct StackNode{
    struct TreeNode* thisNode;
    struct StackNode* next;
} stackNode;

void pushToStack(stackNode** stackTopPointer, treeNode* currentNode){
    stackNode* newNode=malloc(sizeof(stackNode));
    newNode->thisNode=currentNode;
    newNode->next=*stackTopPointer;
    *stackTopPointer=newNode;
}

void popStack(stackNode** stackTopPointer){
    stackNode* tmp=*stackTopPointer;
    *stackTopPointer=(*stackTopPointer)->next;
    free(tmp);
}

bool isValidBST(struct TreeNode* root){
    if(root==0) return 1;
    int lastVal=-2147483648,listIndex=0;//listIndex是为了处理第一个结点的值是-2147483648的情况。
    treeNode* traverse=root;
    stackNode* stackTop=0;
    while(1){
        if(traverse->left){
            pushToStack(&stackTop, traverse);
            traverse=traverse->left;
            stackTop->thisNode->left=0;
        }
        else{
            if(listIndex && traverse->val<=lastVal) return 0;
            lastVal=traverse->val;
            listIndex++;
            if(traverse->right)
                traverse=traverse->right;
            else if(stackTop){
                traverse=stackTop->thisNode;
                popStack(&stackTop);
            }
            else break;
        }
    }
    return 1;
}
```
- 版本一
```c
typedef struct TreeNode treeNode;

typedef struct MyListNode{
    int val;
    struct MyListNode* next
} listNode;

typedef struct StackNode{
    struct TreeNode* thisNode;
    struct StackNode* next;
} stackNode;

void pushToStack(stackNode** stackTopPointer, treeNode* currentNode){
    stackNode* newNode=malloc(sizeof(stackNode));
    newNode->thisNode=currentNode;
    newNode->next=*stackTopPointer;
    *stackTopPointer=newNode;
}

void pushToList(listNode** listPointer, int x){
    listNode* newNode=malloc(sizeof(listNode));
    newNode->val=x;
    newNode->next=*listPointer;
    *listPointer=newNode;
}

void popStack(stackNode** stackTopPointer){
    stackNode* tmp=*stackTopPointer;
    *stackTopPointer=(*stackTopPointer)->next;
    free(tmp);
}

bool isValidBST(struct TreeNode* root){
    if(root==0) return 1;
    treeNode* traverse=root;
    stackNode* stackTop=0;
    listNode* list=0;
    while(1){
        if(traverse->left){
            pushToStack(&stackTop, traverse);
            traverse=traverse->left;
            stackTop->thisNode->left=0;
        }
        else{
            if(list && traverse->val<=list->val) return 0;
            pushToList(&list, traverse->val);
            if(traverse->right)
                traverse=traverse->right;
            else if(stackTop){
                traverse=stackTop->thisNode;
                popStack(&stackTop);
            }
            else break;
        }
    }
    return 1;
}
```