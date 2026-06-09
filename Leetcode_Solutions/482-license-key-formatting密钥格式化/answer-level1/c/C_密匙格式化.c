### 解题思路
技巧 两个栈，倒腾一下
1 所有字符入栈
2 所有字符出栈，然后入新栈，每K个字符填加一个‘-’
3 新栈出栈到字符串
4 返回

如果没有有效字符，返回的是“”不是NULL
要求的各式是从倒数第一组到正数第二组，每组都是K个字符，第一组不必是K个字符。而不是说，第一组和原字符串中的第一组一样，剩下的组都是K个字符，到最后一组凑不出K个字符的话就有几个写几个。（大块注释掉的代码就是后面说的那种错误解法，可以运行，但是结果错误）
### 代码

```c
//--------------------------------------------------------------链表栈
typedef struct Node
{
    char data;
    struct Node* next;
}Node;
Node* newNode(char Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
void push(Node* Head,char Data)
{
    Node* n=newNode(Data);
    n->next=Head->next;
    Head->next=n;
}
char pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    int result= n->data<'a'? n->data : n->data-('a'-'A');
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
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}
//--------------------------------------------------------------解答
char * licenseKeyFormatting(char * S, int K){
    //所有有效字符入栈，如果没有有效字符，直接返回 ""
    Node* stack=newNode('\0');
    while(*S!='\0')
    {
        if(*S!='-')
            push(stack,*S);  
        ++S;
    }
    if(stack->next==0)
    {
        del(stack);
        return "";
    }
    //字符出栈之后进入新栈，每K个字符添加一个‘-’
    Node* resultStack=newNode('\0');
    for(int i=0;stack->next!=0;i=(i+1)%K)
    {
        if(i==0)
            push(resultStack,'-');
        push(resultStack,pop(stack));
    }
    //新栈出栈到字符串
    int l=length(resultStack);
    char* result=(char*)malloc(sizeof(char)*l);
    for(int i=0;i<l;++i)
        result[i]=pop(resultStack);
    result[l-1]='\0';
    //释放栈空间、返回结果
    del(stack);
    del(resultStack);
    return result;
}
//--------------------------------------------------------------错误解答（最后一组不满足有K个字符）
/*typedef struct Node
{
    char data;
    struct Node* next;
}Node;
Node* newNode(char Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
Node* push(Node* Rear,char Data)
{
    Node* n=newNode(Data);
    n->next=Rear->next;
    Rear->next=n;
    return n;
}
char pop(Node* Head,Node** Rear)
{
    Node* n=Head->next;
    if(*Rear==n)
        *Rear=Head;
    Head->next=n->next;
    char result=n->data<'a'?n->data:n->data+'A'-'a';
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
void del(Node* Head,Node** Rear)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
    *Rear=0;
}
//-----------------------------------------------------------解答
char * licenseKeyFormatting(char * S, int K){
    K+=1;
    char* queueTemp=(char*)malloc(sizeof(char)*K);
    int head=0,rear=0;
    Node* resultHead=newNode('\0');
    Node* resultRear=resultHead;

    while(*S!='-')
       resultRear=push(resultRear,*S++);
    resultRear=push(resultRear,*S++);

    while(*S!='\0')
    {
        while(*S!='\0'&&(rear+1)%K!=head)
        {   
            if(*S!='-')
            {
                queueTemp[rear]=*S;
                rear=(rear+1)%K;
            }
            ++S;
        }
        while(head!=rear)
        {
            resultRear=push(resultRear,queueTemp[head]);
            head=(head+1)%K;
        }
        resultRear=push(resultRear,'-');
    }
    free(queueTemp);
    int l=length(resultHead);
    char* result=(char*)malloc(sizeof(char)*l);
    for(int i=0;i<l;++i)
        result[i]=pop(resultHead,&resultRear);
    result[l-1]='\0';
    del(resultHead,&resultRear);
    return result;
}*/
```