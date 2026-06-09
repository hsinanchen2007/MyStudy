### 解题思路
注意1：函数内显式定义的常量字符串，在函数结束时是不会销毁的，仍然可以通过调用该字符串的地址来访问这个字符串。
注意2：152这种数字转换成字符串要另外写一个函数（c语言）

代码多，但是速度和空间还行
![image.png](https://pic.leetcode-cn.com/ee3f9f0ec8e444a1aa63a63727eefa9d18fa39307607a51e01ebecfbe757bfc9-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //-------------------------------------------------------------链表栈
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
    while(Head)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}
//-------------------------------------------------------------数字转换成字符串
char* toString(int Num)
{
    Node* stack=newNode('\0');
    while(Num!=0)
    {
        push(stack,'0'+Num%10);
        Num/=10;
    }
    int l=length(stack);
    char* result=(char*)malloc(sizeof(char)*(l+1));
    result[l]='\0';
    for(int i=0;i<l;++i)
        result[i]=pop(stack);
    del(stack);
    return result;
}
//-------------------------------------------------------------解答
char ** fizzBuzz(int n, int* returnSize){
    *returnSize=n;
    char** result=(char**)malloc(sizeof(char*)**returnSize);
    for(int i=0;i<*returnSize;++i)
        if((i+1)%3==0&&(i+1)%5==0)
            result[i]="FizzBuzz";//注意1
        else if((i+1)%3==0)
            result[i]="Fizz";//注意1
        else if((i+1)%5==0)
            result[i]="Buzz";//注意1
        else
            result[i]=toString(i+1);
    return result;   
}
```