### 解题思路
题目没限定一定是26个字母、包含大小写52个字母、数字、中文.....所以没办法用简单的数组来建立hash表。自己写个链表来记录，既可以动态增长，又可以省空间，记得及时返回效率双百。
![image.png](https://pic.leetcode-cn.com/e6a0931cf2dc1b59dace99efb02ed702ae95e328e32ac027083eb53b4572edb0-image.png)

### 代码

```c
////////////////////////////////////////////////////////////////////链表存储
typedef struct Node
{
    char data;
    int times;
    struct Node* next;
}Node;
//建立链表节点
Node* newNode(char Data,int Times)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->times=Times;
    n->next=0;
    return n;
}
//统计字符Data出现的频率
void push(Node* Head,char Data)
{
    for(Node* n=Head->next;n!=0;n=n->next)
        if(n->data==Data)
        {
            ++(n->times);
            return;
        }    
    Node* n=newNode(Data,1);
    n->next=Head->next;
    Head->next=n;
}
//从链表中减少一次Data出现的频率，如果减完出负数，说明无法匹配
bool pop(Node* Head,char Data)
{
    for(Node* n=Head->next;n!=0;n=n->next)
        if(n->data==Data)
            return --(n->times)<0 ? false : true;
    return false;
}
//释放内存
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}
////////////////////////////////////////////////////////////////////解答
bool CheckPermutation(char* s1, char* s2){
    //统计s1的字符出现频率
    Node* link=newNode('\0',0);
    for(int i=0;s1[i]!='\0';++i)
        push(link,s1[i]);
    //从链表中剔除s2包含的字符
    for(int i=0;s2[i]!='\0';++i)
        if(!pop(link,s2[i]))
        {
            del(link);
            return false;
        }
    del(link);
    return true;
}
```