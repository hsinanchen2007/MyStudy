### 解题思路
判断正负。借用栈。
代码虽然多，但是省空间
![image.png](https://pic.leetcode-cn.com/75de253ad325db1943ddc8d4c8db034c8ec0f3f63c7244482962d5033794dc75-image.png)
### 代码

```c
//----------------------------------------------------栈
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
        ++result;
        Head=Head->next;
    }
    return result;
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
//----------------------------------------------------解答
char * convertToBase7(int num){
    //flag==1表示负数
    int flag=0;
    if(num<0)
    {
        flag=1;
        num*=(-1);   
    }
    //运算，入栈
    Node* stack=newNode('\0');
    do
    {
        push(stack,num%7+'0');
        num/=7;
    }while(num!=0);
    //根据正负判断结果需要多少字符位置
    int l=flag?length(stack)+1:length(stack);
    char* result=(char*)malloc(sizeof(char)*(l+1));
    if(flag)result[0]='-';
    //负数的第一位是‘-’所以从result[1]开始，负数的时候flag是1,所以直接从flag开始写
    for(int i=flag;i<l;++i)
        result[i]=pop(stack);
    result[l]='\0';
    del(stack);
    return result;
}
```