### 解题思路
1.不是单纯的字符串匹配，字符相等&&字符位置相同 算一个 公牛；字符相同&&位置不同 算一个 母牛。题目的一个难点在于secret中的字符是“消耗性的”，就是说guess中的字符和secret中的字符成功匹配（无论是公牛还是母牛）一个，secret的字符就少（不可再用来匹配）一个。
2.注意AB都是0个的时候，输出）0A0B。
3.把int转成字符借用一个链表栈实现

不算快，但是省内存
![image.png](https://pic.leetcode-cn.com/8600988e9eba1f75e3fba78529e2ead372b953f19ce223fdd348b2cfc9810171-image.png)

### 代码

```c
//----------------------------------------------链表栈
typedef struct Node{
    char data;
    struct Node* next;
}Node;
//新建结点
Node* newNode(char Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
//入栈
void push(Node* Head,char Data)
{
    Node* n=newNode(Data);
    n->next=Head->next;
    Head->next=n;
}
//出栈
char pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    char result=n->data;
    free(n);
    return result;
}
//栈中元素个数
int length(Node* Head)
{
    int result=0;
    for(Node* n=Head->next;n!=0;n=n->next)
        ++result;
    return result;
}
//释放栈内存
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}
//----------------------------------------------解答
char * getHint(char * secret, char * guess){
    //先数出完全匹配的字符（匹配成功之后改成A代表被消耗，不能再用来匹配）
    int A=0;
    for(int i=0;secret[i]!='\0'&&guess[i]!='\0';++i)
        if(secret[i]==guess[i])
        {
            ++A;
            secret[i]='A';
            guess[i]='A'; 
        }
    //再统计字符匹配但是位置不匹配的
    int B=0;
    for(int i=0;guess[i]!='\0';++i)
        if(guess[i]!='A')
            for(int j=0;secret[j]!='\0';++j)
                if(guess[i]==secret[j])
                {
                    ++B;
                    secret[j]='A';
                    break;
                }
    
    //通过链表栈，把int数字转换成字符串（注意考虑AB为零的情况要输出0A0B）
    Node* stack=newNode('\0');
    push(stack,'B');
    if(B==0)push(stack,'0');
    while(B!=0)
    {
        push(stack,'0'+B%10);
        B/=10;
    }
    push(stack,'A');
    if(A==0)push(stack,'0');
    while(A!=0)
    {
        push(stack,'0'+A%10);
        A/=10;
    }
    int l=length(stack);
    char* result=(char*)malloc(sizeof(char)*(l+1));
    result[l]='\0';
    for(int i=0;i<l;++i)
        result[i]=pop(stack);
    del(stack);

    return result;
}
```