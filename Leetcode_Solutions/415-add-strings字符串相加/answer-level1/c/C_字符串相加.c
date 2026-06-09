### 解题思路
利用栈进行从低位到高位的相加
flag是进位标志
### 代码

```c
//------------------------------------------------------链表栈
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* newNode(int Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
void push(Node* Head,int Data)
{
    Node* n=newNode(Data);
    n->next=Head->next;
    Head->next=n;
}
int pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    int result=n->data;
    free(n);
    return result;
}
int lenght(Node* Head)
{
    int result=0;
    while(Head->next!=0)
    {
        result++;
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

//------------------------------------------------------解答
char * addStrings(char * num1, char * num2){

    Node* num1Stack=newNode(0);
    Node* num2Stack=newNode(0);
    for(char* iter=num1;*iter!='\0';++iter)push(num1Stack,*iter-'0');
    for(char* iter=num2;*iter!='\0';++iter)push(num2Stack,*iter-'0');

    Node* resultStack=newNode(0),*iter1=num1Stack->next,*iter2=num2Stack->next;
    int flag=0;
    while(iter1!=0&&iter2!=0)
    {
        if(iter1->data+iter2->data+flag>9)
        {
            push(resultStack,(iter1->data+iter2->data+flag)%10);
            flag=1;
        }
        else
        {
            push(resultStack,iter1->data+iter2->data+flag);
            flag=0;
        }
        iter1=iter1->next;
        iter2=iter2->next; 
    } 
    while(iter1!=0)
    {
        if(iter1->data+flag>9)
        {
            push(resultStack,(iter1->data+flag)%10);
            flag=1;
        }
        else
        {
            push(resultStack,iter1->data+flag);
            flag=0;
        }
        iter1=iter1->next;
    }
    while(iter2!=0)
    {
        if(iter2->data+flag>9)
        {
            push(resultStack,(iter2->data+flag)%10);
            flag=1;
        }
        else
        {
            push(resultStack,iter2->data+flag);
            flag=0;
        }
        iter2=iter2->next;
    }
    if(flag==1)
        push(resultStack,flag);
    del(num1Stack);
    del(num2Stack);

    int l=lenght(resultStack);
    char* result=(char*)malloc(sizeof(char)*(l+1));
    for(int i=0;i<l;++i)
        result[i]='0'+pop(resultStack);
    result[l]='\0';
    del(resultStack);

    return result;
}
```