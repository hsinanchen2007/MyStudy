### 解题思路
字符串+格式的输出对C语言不太友好。
方法是暴力法，不过控制输出的格式麻烦
![image.png](https://pic.leetcode-cn.com/69232584e6655e9f4d89314ea9f4a11b03cdf2ce11fc066af23b871f6ddcf7c9-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//-------------------------------------------------栈
typedef struct Node
{
    char* data;
    struct Node* next;
}Node;
Node* newNode(char* Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
void push(Node* Head,char* Data)
{
    Node* n=newNode(Data);
    n->next=Head->next;
    Head->next=n;
}
char* pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    char* result=n->data;
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
//-------------------------------------------------辅助函数
int bits(int Num)
{
    int result=0;
    while(Num!=0)
    {
        if(Num&1==1)++result;
        Num=Num>>1;
    }
    return result;
}
char* toString(int Hour,int Min)
{
    char stack[5];
    int top=0;
    if(Min==0)
    {    
        stack[top++]='0';
        stack[top++]='0';
    }
    if(0<Min&&Min<10)
    {
        stack[top++]='0'+Min%10;
        stack[top++]='0';
    }
    else
        while(Min!=0)
        {
            stack[top++]='0'+Min%10;
            Min/=10;
        }
    stack[top++]=':';
    if(Hour==0)
        stack[top++]='0';
    while(Hour!=0)
    {
        stack[top++]='0'+Hour%10;
        Hour/=10;
    }
    int length=top;
    char* result=(char*)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;++i)
        result[i]=stack[--top];
    result[length]='\0';
    return result;
}
//-------------------------------------------------解答
char ** readBinaryWatch(int num, int* returnSize){
    Node* stack=newNode(0);
    for(int h=0;h<12;++h)
        for(int m=0;m<60;++m)
            if(bits(h)+bits(m)==num)
                push(stack,toString(h,m));
    *returnSize=length(stack);
    char** result=(char**)malloc(sizeof(char*)**returnSize);
    for(int i=0;i<*returnSize;++i)
        result[i]=pop(stack);
    del(stack);
    return result;
}
```