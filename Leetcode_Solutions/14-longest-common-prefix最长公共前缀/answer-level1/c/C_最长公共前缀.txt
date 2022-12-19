### 解题思路
/*测试用例题目没给说清楚*/
输入strsSize==0的时候 return "";
输入strsSize==1的时候 return strs[0];

返回空的时候是返回 "" 不是返回一个 值为null的指针
只有一行的时候不是返回空，而是返回仅有的那一行就行
### 代码

```c
//链表节点
typedef struct node{
    char data;
    struct node* next;
}node;
//建立新节点
node* newNode(char* C)
{
    node* n=(node*)malloc(sizeof(node));
    n->data=C==0?'\0':*C;
    n->next=0;
    return n;
}
//插入一个元素
void push(node* StackHead,char C)
{
    node* n=(node*)malloc(sizeof(node));
    n->data=C;
    n->next=StackHead->next;
    StackHead->next=n;
}
//弹出一个元素
char pop(node* StackHead)
{
    char result=StackHead->next->data;
    node* del=StackHead->next;
    StackHead->next=del->next;
    free(del);
    return result;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
        return "";
    else if(strsSize==1)
        return strs[0];
    //建立个链表栈，有头结点
    node* stack=newNode(0);
    //公共字符串长度，“到当前列还是相同”标志
    int length=0,flag=1;
    for(int col=0;flag;++col)
    {   //有一个字符串到头了 或者 有一个字符串当前列的字符不同与其他，后面列不看了，标志位变0.
        for(int row=0;row<strsSize-1;++row)
            if(strs[row][col]=='\0'||strs[row+1][col]=='\0'||strs[row][col]!=strs[row+1][col])
            {
                flag=0;
                break;
            }
        //当前列，所有字符串的字符都相同
        if(flag)
        {
            ++length;
            push(stack,strs[0][col]);
        }
    }
    //从栈中把元素整理好，输出
    char* result=(char*)malloc(sizeof(char)*(length+1));
    result[length--]='\0';
    while(length>=0)
        result[length--]=pop(stack);
    free(stack);
    return result;
}
```