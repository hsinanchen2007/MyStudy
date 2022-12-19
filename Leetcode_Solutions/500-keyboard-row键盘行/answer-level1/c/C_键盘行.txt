### 解题思路
写一个链表栈存放符合条件的字符串
写一个哈希表记录字母所在的行

代码看着多，但是效率双百
![image.png](https://pic.leetcode-cn.com/2d11f3be7984a9b3491a7c8fb7dfb2da6217e832821a2b6645e18db36b39b619-image.png)



### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//-------------------------------------------------链表栈
typedef struct Node
{
    char* string;
    struct Node* next;    
}Node;
Node* newNode(char* String)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->string=String;
    n->next=0;
    return n;
}
void push(Node* Head, char* String)
{
    Node* n=newNode(String);
    n->next=Head->next;
    Head->next=n;
}
char* pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    char* result=n->string;
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
//-------------------------------------------------解答
char ** findWords(char ** words, int wordsSize, int* returnSize){
    //哈希表和栈
    int hash[26];   Node* stack=newNode(0);
    hash['q'-'a']=1;hash['w'-'a']=1;hash['e'-'a']=1;hash['r'-'a']=1;hash['t'-'a']=1;
    hash['y'-'a']=1;hash['u'-'a']=1;hash['i'-'a']=1;hash['o'-'a']=1;hash['p'-'a']=1;
    hash['a'-'a']=2;hash['s'-'a']=2;hash['d'-'a']=2;hash['f'-'a']=2;hash['g'-'a']=2;
    hash['h'-'a']=2;hash['j'-'a']=2;hash['k'-'a']=2;hash['l'-'a']=2;
    hash['z'-'a']=3;hash['x'-'a']=3;hash['c'-'a']=3;hash['v'-'a']=3;hash['b'-'a']=3;
    hash['n'-'a']=3;hash['m'-'a']=3;

    for(int i=0;i<wordsSize;++i)
    {
        int flag=1,row=hash[(words[i][0]<'a'?words[i][0]+('a'-'A'):words[i][0])-'a'];
        for(int j=0;words[i][j]!='\0';++j)
            if(row!=hash[(words[i][j]<'a'?words[i][j]+('a'-'A'):words[i][j])-'a'])
            {
                flag=0;
                break;
            }   
        if(flag)
            push(stack,words[i]);
    }

    *returnSize=length(stack);
    char** result=(char**)malloc(sizeof(char*)**returnSize);
    for(int i=0;i<*returnSize;++i)
        result[i]=pop(stack);
    del(stack);

    return result;
}
```