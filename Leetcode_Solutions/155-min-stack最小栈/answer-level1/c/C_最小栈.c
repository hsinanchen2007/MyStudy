### 解题思路
用链表完成栈功能

最小值计算：

栈的特点是先进后出，如果有一个很小的值 i 先入栈，那么后面入栈的元素如果大于 i 就没必要记录。因为后入栈且大于i的元素一定会比i先出栈，所以那些元素的出入根本不影响栈的最小值。但是如果后入栈的元素有小于等于 i 的，那么就应该记录这些元素的值（由此可以看出，按记录时间的先后排列==从大到小排列），因为这些元素的出入会影响栈的最小值。

记录最小值的元素同样应该用栈来储存

### 代码

```c
//----------------------------------------------------首先用链表组成一个最普通的栈
//链表（栈）节点
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
//入栈
void linkPush(Node* Head,int Data)
{
    Node* n=newNode(Data);
    n->next=Head->next;
    Head->next=n;
}
//出栈
int linkPop(Node* Head)
{
    Node* del=Head->next;
    Head->next=del->next;
    int result=del->data;
    free(del);
    return result;
}
//判断栈空
bool linkEmpty(Node* Head)
{
    return Head->next==0?true:false;
}
//释放栈内存
void linkDel(Node* Head)
{
    while(Head!=0)
    {
        Node* del=Head;
        Head=Head->next;
        free(del);
    }
}

//-------------------------------------题目要求的最小栈包含两个内容 一个是储存数据用的数据栈，一个是储存最小值用的记录栈
typedef struct {
    struct Node* headMin;//记录栈
    struct Node* headData;//数据栈
} MinStack;

/** initialize your data structure here. */
//最小栈用两个普通栈组建
MinStack* minStackCreate() {
    MinStack* stack=(MinStack*)malloc(sizeof(MinStack));
    stack->headMin=newNode(0);
    stack->headData=newNode(0);
    return stack;
}
//最小栈入栈
void minStackPush(MinStack* obj, int x) {
    //如果最小栈空，就把第一个元素写入数据栈和记录栈
    if(linkEmpty(obj->headData)&&linkEmpty(obj->headMin))
    {
        linkPush(obj->headData,x);
        linkPush(obj->headMin,x);
    }
    //如果非空，就把元素写入数据栈，如果元素的值不大于最小栈的最小值，也要写入记录栈
    else
    {
        linkPush(obj->headData,x);
        if(x<=obj->headMin->next->data)
            linkPush(obj->headMin,x); 
    }
}
//最小栈出栈
void minStackPop(MinStack* obj) {
    //空栈不进行操作
    if(linkEmpty(obj->headData)&&linkEmpty(obj->headMin))
        return;
    //如果出栈的值是最小栈的最小值，记录栈也要进行一次出栈操作
    int num=linkPop(obj->headData);
    if(num==obj->headMin->next->data)
        linkPop(obj->headMin);
}
//最小栈栈顶值：返回数据栈的栈顶值
int minStackTop(MinStack* obj) {
    return obj->headData->next->data;
}
//最小栈的最小值：返回记录栈栈顶值
int minStackGetMin(MinStack* obj) {
    return obj->headMin->next->data;
}
//先释放数据栈和记录栈的内存，再释放最小栈内存
void minStackFree(MinStack* obj) {
    linkDel(obj->headMin);
    linkDel(obj->headData);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```