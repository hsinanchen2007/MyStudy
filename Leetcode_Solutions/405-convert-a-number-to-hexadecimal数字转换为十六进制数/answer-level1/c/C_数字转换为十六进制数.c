### 解题思路
正常的进制转换+如果是负数就先强制转换成unsigned类型。
借用了一下栈，虽然自己写栈，但是还是可以双百的
![image.png](https://pic.leetcode-cn.com/98ecb7fcff1de60b8661818800de8cf0d1831a22c2aa1d483c3952c47292d738-image.png)

### 代码

```c
//-------------------------------------------------------------栈
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
    char result=n->data;
    free(n);
    return result;
}
int length(Node* Head)
{
    int result=0;
    while(Head->next!=0)
    {
        Head=Head->next;
        ++result;   
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
//-------------------------------------------------------------解答
char * toHex(int num){
    if(num==0)return "0";
    Node* stack=newNode('\0');
    unsigned n=(unsigned)num;
    while(n!=0)
    {
        switch(n%16)
        {
            case 0 : push(stack,'0'); break;
            case 1 : push(stack,'1'); break;
            case 2 : push(stack,'2'); break;
            case 3 : push(stack,'3'); break;
            case 4 : push(stack,'4'); break;
            case 5 : push(stack,'5'); break;
            case 6 : push(stack,'6'); break;
            case 7 : push(stack,'7'); break;
            case 8 : push(stack,'8'); break;
            case 9 : push(stack,'9'); break;
            case 10: push(stack,'a'); break;
            case 11: push(stack,'b'); break;
            case 12: push(stack,'c'); break;
            case 13: push(stack,'d'); break;
            case 14: push(stack,'e'); break;
            case 15: push(stack,'f'); break;
        }
        n/=16;
    }
    int l=length(stack);
    char* result=(char*)malloc(sizeof(char)*(l+1));
    for(int i=0;i<l;++i)
        result[i]=pop(stack);
    result[l]='\0';
    del(stack);
    return result;
}
```