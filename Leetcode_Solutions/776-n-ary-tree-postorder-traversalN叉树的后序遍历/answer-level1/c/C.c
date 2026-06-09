### 解题思路
原来只知道傻傻的简单递归。

这里利用了前序遍历的方法，前序遍历是弹出根节点的后马上存入孩子节点，但孩子节点是逆序的，从而保证左孩子始终在栈顶，以满足根-左-右的特点。

所以后序遍历的时候，要将前序遍历中存入孩子节点的顺序按正常来存，这样右孩子就出现在栈顶，最终就是根-右-左的顺序。

这与后序遍历的特点左-右-根正好相反，所以最后翻转一下即可。

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXSIZE 10000

typedef struct{
    struct Node* data[MAXSIZE];
    int top;
}SqStack;

SqStack* CreateStack();
bool StackEmpty(SqStack* S);
bool StackFull(SqStack* S);
void Push(SqStack* S, struct Node* node);
void Pop(SqStack* S);
void PrintStack(SqStack* S);

int* postorder(struct Node* root, int* returnSize) {
    int* nums;
    nums = (int *)malloc(sizeof(int) * MAXSIZE);

    if(!root){
        *returnSize = 0;
        return nums;
    }

    SqStack* S = CreateStack();
    int i=0, j;

    Push(S, root);
    while( ! StackEmpty(S) ){
        //PrintStack(S);

        struct Node* temp = malloc(sizeof(struct Node));
        temp = S->data[S->top];
        nums[i++] = temp->val;

        Pop(S);
        for(j=0; j<temp->numChildren; j++)
            Push(S, temp->children[j]);
    }

    *returnSize = i;
    for(i=0; i<(*returnSize)/2; i++){
        j = nums[i];
        nums[i] = nums[*returnSize-1-i];
        nums[*returnSize-1-i] = j;
    }

    return nums;
}

SqStack* CreateStack(){
    SqStack* S;
    S = (SqStack *)malloc(sizeof(SqStack));
    S->top = -1;
    return S;
}

bool StackEmpty(SqStack* S){
    return S->top == -1;
}

bool StackFull(SqStack* S){
    return S->top+1 == MAXSIZE;
}

void Push(SqStack* S, struct Node* node){
    if( ! StackFull(S) ){
        S->top++;
        S->data[S->top] = node;
    }
}

void Pop(SqStack* S){
    if( ! StackEmpty(S) )
        S->top--;
}

void PrintStack(SqStack* S){
    int i;
    for(i=0; i<=S->top; i++)
        printf("%d ", S->data[i]->val);
    printf("\n");
}

```