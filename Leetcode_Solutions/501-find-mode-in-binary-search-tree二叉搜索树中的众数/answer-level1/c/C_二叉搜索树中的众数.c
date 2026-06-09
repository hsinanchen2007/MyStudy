### 解题思路
统计数字出现的频率
去除频率最低的数字
输出
### 代码

```c
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
//---------------------------------------------------------链表
typedef struct Node{
    int val;
    int times;
    struct Node* next;
}Node;
Node* newNode(int Val,int Times)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=Val;
    n->times=Times;
    n->next=0;
    return n;
}
void push(Node* Head,int Val)
{
    for( Node* iter=Head->next;iter!=0;iter=iter->next)
        if(iter->val==Val)
        {
            ++(iter->times);
            return;
        }
    Node* n=newNode(Val,1);
    n->next=Head->next;
    Head->next=n;    
}
int pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    int result=n->val;
    free(n);
    return result;
}
int length(Node* Head)
{
    int result=0;
    while(Head->next!=0)
    {
        ++result;
        Head=Head->next;
    }
    return result;
}
void onlyMax(Node* Head)
{
    int max=-1;
    for(Node* iter=Head->next;iter!=0;iter=iter->next)
        if(max<iter->times)
            max=iter->times;
    Node* iter=Head;
    while(iter->next!=0)
    {
        if(max!=iter->next->times)
        {
            Node* n=iter->next;
            iter->next=n->next;
            free(n);
            continue;
        }
        iter=iter->next;
    }
}
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head->next;
        Head=Head->next;
        free(n);
    }
}
//---------------------------------------------------------遍历二叉树
void count(Node* Link,struct TreeNode* Root)
{
    if(Root==0) return;
    push(Link,Root->val);
    count(Link,Root->left);
    count(Link,Root->right);
}
//---------------------------------------------------------解答
int* findMode(struct TreeNode* root, int* returnSize){
    Node* linkHead=newNode(0,0);
    count(linkHead,root);
    onlyMax(linkHead);    
    *returnSize=length(linkHead);
    int* result=(int*)malloc(sizeof(int)**returnSize);
    for(int i=0;i<*returnSize;++i)
        result[i]=pop(linkHead);
    del(linkHead);
    return result;
}
```