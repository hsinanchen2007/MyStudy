### 解题思路
链表做栈进行匹配。

### 代码

```c
//链表节点
typedef struct Node{
    char data;
    struct Node* next;
}node;
//建立新节点
node* newNode(char* C){
    node* n=(node*)malloc(sizeof(node));
    n->data=C==0?'\0':*C;
    n->next=0;
    return n;
}
//入栈
void push(node* StackHead,char* C){
    node* n=(node*)malloc(sizeof(node));
    n->data=C==0?'\0':*C;
    n->next=StackHead->next;
    StackHead->next=n;
}
//出栈
void pop(node* StackHead){
    node* del=StackHead->next;
    StackHead->next=del->next;
    free(del);
}
//查看栈顶元素
char top(node* StackHead){
    return StackHead->next->data;
}
//判断栈空
int empty(node* StackHead){
    return StackHead->next==0?1:0;
}
bool isValid(char * s){

    if(s==0)return 1;

    int result=1;
    node* stack=newNode(0);
    while(*s!='\0'&&result){
        //情况一 前半个括号
        if(*s=='{'||*s=='['||*s=='(')
            push(stack,s);
        //如果是后半个括号，且栈空，无法匹配
        else if(empty(stack))
            result=0;
        //如果是后半个括号，和栈里面的匹配。成功，出栈一个，不成功，直接就不成功。
        else
            switch(top(stack)){
            case '{':
                if(*s=='}')
                    pop(stack);
                else
                    result=0;
                break;
            case '[':
                if(*s==']')
                    pop(stack);
                else
                    result=0;
                break;
            case '(':
                if(*s==')')
                    pop(stack);
                else
                    result=0;
                break;
            }
        ++s;       
    }
    //一套匹配下来，还有没匹配完的括号，不行
    if(!empty(stack)) result=0;

    free(stack);
    return result;
}
```