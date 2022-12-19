### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/ad6b184986c73c56e61539f7d66615cb1f32d8da998a580433fdc827ab24d836-%E6%8D%95%E8%8E%B7.PNG)


果然过几天再做就会有思路。感觉有点像深度优先搜索。

第一步，如果节点有左孩子，则入栈；
第二步，每弹出一个节点的同时，检查其是否有右孩子，有的话就存入该节点的右孩子以及该孩子的左孩子和左孩子...

### 代码

```c
/*
// Definition for Stack.
#define MAXSIZE 100
typedef struct{
    struct TreeNode* data[MAXSIZE];
    int top;
}SqStack;
SqStack* CreateStack();
bool StackEmpty(SqStack* S);
bool StackFull(SqStack* S);
void Push(SqStack* S, struct TreeNode* node);
int Pop(SqStack* S);
struct TreeNode* StackPeek(SqStack* S);
void PrintStack(SqStack* S);
*/

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* ans;
    ans = (int *)malloc(sizeof(int) * MAXSIZE);
    int i = 0;

    if(!root){
        *returnSize = 0;
        return ans;
    }

    SqStack* S = CreateStack();
    //如果节点有左孩子，则入栈
    while(root){
        Push(S, root);
        root = root->left;
    }

    //每弹出一个节点的同时，检查其是否有右孩子，有的话就存入该节点的右孩子以及该孩子的左孩子...
    while(!StackEmpty(S)){
        struct TreeNode* temp = StackPeek(S);
        ans[i++] = Pop(S);

        if(temp->right){
            temp = temp->right;
            Push(S, temp);
            
            while(temp->left){
                Push(S, temp->left);
                temp = temp->left;
            }
        }
    }

    *returnSize = i;
    return ans;
}
