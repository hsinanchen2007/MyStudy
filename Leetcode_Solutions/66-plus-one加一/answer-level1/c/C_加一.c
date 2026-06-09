### 解题思路
输入的数位数会很大很大很大，所以不能把数组里的数提取出来加一再放回去。

通过一个链表栈可以完成操作

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//链表节点
 typedef struct Node{
     int data;
     struct Node* next;
 }Node;
//新建节点
Node* newNode(int Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
//头插法入栈
void push(Node* Head,int Data)
{
    Node* n=newNode(Data);
    n->next=Head->next;
    Head->next=n;
}
//出栈
int pop(Node* Head)
{
    Node* del=Head->next;
    Head->next=del->next;
    int result=del->data;
    free(del);
    return result;
}
//栈里的元素数量
int lengthOf(Node* Head)
{
    int length=0;
    while(Head!=0)
    {
        ++length;
        Head=Head->next;
    }
    return length-1;
}
//销毁链表栈
void delStack(Node* Head)
{
    while(Head!=0)
    {
        Node* del=Head;
        Head=Head->next;
        free(del);
    }
}

int* plusOne(int* digits, int digitsSize, int* returnSize){
    //数字从高位到低位入栈
    Node* stack=newNode(-1);
    for(int i=0;i<digitsSize;++i)
        push(stack,digits[i]);

    //flag是进位标志
    int flag=1;
    //从个位开始加1
    Node* iter=stack->next;
    //还要进一个位
    while(flag)
    {
        //本位数加一
        iter->data=iter->data+1;
        //本位加一之后不需要进位
        if(iter->data<10)
            flag=0;
        //本位加一之后需要进位
        else
        {
            //本位对10取余
            iter->data=iter->data%10;
            //向后一位
            if(iter->next!=0)
                iter=iter->next;
            //如果向后没有位数了，新建一位
            else
            {
                //新建的位数初始为0
                iter->next=newNode(0);
                iter=iter->next;
            }
        }
    }

    //统计链表栈有多少个元素
    *returnSize=lengthOf(stack);
    int* result=(int*)malloc(sizeof(int)**returnSize);
    //把栈里的数存到新申请的数组内存中
    for(int i=*returnSize-1;i>=0;--i)
        result[i]=pop(stack);
    //释放链表栈的空间
    delStack(stack);

    return result;
}
```