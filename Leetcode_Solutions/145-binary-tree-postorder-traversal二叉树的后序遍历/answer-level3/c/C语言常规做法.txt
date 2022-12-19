核心内容：一，先看看目前节点左边有没有节点，有的话目前节点入栈，目前节点跳到左边节点，并断开这两个节点；二，一不满足，则看看目前节点右边有没有节点，有的话目前节点入栈，目前节点跳到右边节点，并断开这两个节点；三，一二均不满足，则将目前节点的值放到数组，如果栈不为空，目前节点换成栈顶并去掉栈顶元素，否则跳出循环。
说实话我不太理解为什么后序遍历难度是困难而前序和中序只是中等，感觉都差不多。后序遍历的代码是从[中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/cyu-yan-chang-gui-zuo-fa-by-bevischou-108/)的代码中复制粘贴再改一下while循环中的代码得到的。
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

int* postorderTraversal(struct TreeNode* root, int* returnSize){
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
        else if(traverse->right){
            pushToStack(&stackTop,traverse);
            traverse=traverse->right;
            stackTop->thisNode->right=0;
        }
        else{
            pushToList(&tmp,traverse->val);
            *returnSize=*returnSize+1;
            if(stackTop){
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