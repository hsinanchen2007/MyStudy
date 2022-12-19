### 解题思路
通过栈匹配相应括号

### 代码

```c
//链表节点
typedef struct Node
{
    char c;
    struct Node * next;
}node;
//入栈
bool pushStack(node* stack,char *s){
    if(stack==0||s==0)
        return 0;
    node* newNode=(node*)malloc(sizeof(node));
    newNode->c=*s;
    newNode->next=stack->next;
    stack->next=newNode;
    return 1;
}
//入队 !!!注意因为队尾指针是需要移动的，因为传值方式的原因，队列尾指针的移动放在行数外进行
bool pushQueue(node* rear,char *s){
    if(rear==0||s==0)
        return 0;
    node* newNode=(node*)malloc(sizeof(node));
    newNode->c=*s;
    newNode->next=rear->next;
    rear->next=newNode;
    return 1;
}
//出栈
bool popStack(node* stack,char *s){
    if(stack->next==0||stack==0)
        return 0;
    if(s!=0)
        *s=stack->next->c;
    node* delet=stack->next;
    stack->next=delet->next;
    free(delet);
    return 1;
}
//出队
bool popQueue(node* head,char *s){
    if(head->next==0||head==0)
        return 0;
    if(s!=0)
        *s=head->next->c;
    node* delet=head->next;
    head->next=delet->next;
    free(delet);
    return 1;
}
char * removeOuterParentheses(char * S){

    //建立一个栈
    node* stack=(node*)malloc(sizeof(node));
    stack->next=0;
    //建立一个缓存队列
    node* head=(node*)malloc(sizeof(node));
    head->next=0;
    node* rear=head;
    //处理字符串
    int length=0;
    while(*S!='\0')
    {
        //栈非空，*S是内层括号，或者是最外层的')'
       if(stack->next!=0)
        {   
            //如果是')'，先出栈
            if(*S==')')
            {
                popStack(stack,0);
                //如果不是最外层括号的')'，入队
                if(stack->next!=0)
                {
                    pushQueue(rear,S);
                    rear=rear->next;//!!!
                    ++length;
                }
            }
            //如果是'('入栈+入队即可
            else
            {
                pushStack(stack,S);
                pushQueue(rear,S);
                rear=rear->next;//!!!
                ++length;
            }
        }
        //栈是空的就代表当前字符*S是最外层括号的'(',进栈但不入队
        else
            pushStack(stack,S);
        ++S;
    }
    //导出队内元素
    char *result =(char*)malloc(sizeof(char)*(length+1));
    int j=0;
    while(head->next!=0)
        popQueue(head,result+(j++));

    result[length]='\0';
    free(stack);
    free(head);
    return result;
}
```