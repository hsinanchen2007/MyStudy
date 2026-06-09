核心内容：遇到一个节点，先看看是不是在栈顶，不是的话，入栈并记录下val值。接着看看左边还有没有，有的话遍历指针指向左边节点，并断开目前节点与左节点，循环；左边没有的话看右边，操作与左边相似；如果左右都没有退栈，遍历指针指向栈顶。
该做法把树都拆了，感觉不太好。
为了主干程序易读，部分代码写成函数。
```c
typedef struct StackNode{
    struct TreeNode* thisNode;
    struct StackNode* next;
} stackNode;

typedef struct NodeOfList{
    int val;
    struct NodeOfList* next;
} listNode;

typedef struct TreeNode treeNode;

void pushToStack(stackNode** stack, treeNode* currentNode){
    stackNode* node=malloc(sizeof(stackNode));
    node->thisNode=currentNode;
    node->next=*stack;
    *stack=node;
}

void pushToList(listNode** list, int x){
    listNode* node=malloc(sizeof(listNode)); 
    node->val=x;
    node->next=*list;
    *list=node;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    if(root==0) return 0;
    treeNode* traverse=root;
    stackNode* stackTop=0,*tmpStack;
    listNode* tmp=0,*tmpList;
    do{
        if(stackTop==0 || traverse!=stackTop->thisNode){
            pushToStack(&stackTop,traverse);
            *returnSize=*returnSize+1;
            pushToList(&tmp,traverse->val);
        }
        if(traverse->left){
            traverse=traverse->left;
            stackTop->thisNode->left=0;
        }
        else if(traverse->right){
            traverse=traverse->right;
            stackTop->thisNode->right=0;
        }
        else{
            tmpStack=stackTop;
            stackTop=stackTop->next;
            if(stackTop)
                traverse=stackTop->thisNode;
            free(tmpStack);
        }
    }while(stackTop);
    int i=*returnSize;
    int* res=malloc(*returnSize *sizeof(int));
    while(tmp){
        res[--i]=tmp->val;
        tmpList=tmp;
        tmp=tmp->next;
        free(tmpList);
    }
    return res;
}
```