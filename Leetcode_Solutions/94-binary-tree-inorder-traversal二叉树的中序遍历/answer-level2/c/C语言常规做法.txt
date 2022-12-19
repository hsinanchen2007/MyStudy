核心内容：一，先看看目前节点左边有没有节点，有的话目前节点入栈，目前节点跳到左边节点，并断开这两个节点；二，如果左边没有节点，那么将目前节点的值放到数组，再看看右边有没有节点，1）有的话，目前节点跳到右边节点，2）如果没有且栈不为空，目前节点换成栈顶并去掉栈顶元素，3）如果栈为空，结束循环。
做该题的时候在退出循环的条件卡住了，尝试过while(stackTop||traverse->left||traverse->right)，其实下面的代码的结束点就是目前节点左右都空且栈也空，但无论是do-while结构还是while，用while(stackTop||traverse->left||traverse->right)都会导致在某些情况下缺最后一个元素，因为最后一个节点在加入到数组前就因为不满足条件而结束了。
这个做法左边为空的中间的节点都是不用入栈的，且不会用多余的空间（用链表实现栈和按顺序记录val），缺点是代码较长，用数组就不存在malloc来free去的问题，但有点强迫症（或者抠门？），不想占用用不着的空间。
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

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    if(root==0) return 0;
    treeNode* traverse=root;
    stackNode* stackTop=0,*tmpStack;
    listNode* tmp=0,*tmpList;
    while(1){ 
        if(traverse->left){
            pushToStack(&stackTop,traverse);
            traverse=traverse->left;
            stackTop->thisNode->left=0;
        }           
        else{
            pushToList(&tmp,traverse->val);
            *returnSize=*returnSize+1;
            if(traverse->right)
                traverse=traverse->right;
            else if(stackTop){
                traverse=stackTop->thisNode;
                tmpStack=stackTop;
                stackTop=stackTop->next;
                free(tmpStack);
            }
            else break;
        }
    }
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