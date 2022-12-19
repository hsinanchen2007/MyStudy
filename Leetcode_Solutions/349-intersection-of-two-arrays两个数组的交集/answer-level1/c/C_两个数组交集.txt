### 解题思路
考察库函数的题，对C不友好，没什么技巧，自己写的数据结构

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //_________________________________________建立链表存储
//链表节点
 typedef struct Node{
     int data;
     struct Node* next;
 }Node;
//新建节点
Node* newNode(int Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
//查看交集中是否已经有这个字符_插入新字符前判断用
bool theOnly(Node* Head,int Data)
{
    Node* n=Head->next;
    while(n!=0)
        if(n->data==Data)
            return false;
        else
            n=n->next;
    return true;
}
//插入字符
void push(Node* Head,int Data)
{
    if(theOnly(Head,Data))
    {
        Node* n=newNode(Data);
        n->next=Head->next;
        Head->next=n;
    }
}
//导出一个字符
int pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    int result=n->data;
    free(n);
    return result;
}
//测量字符总数
int linkLength(Node* Head)
{
    int result=0;
    while(Head->next!=0)
    {
        ++result;
        Head=Head->next;   
    }
    return result;
}
//释放链表内存
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}
//_________________________________________解答
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    //建立链表
    Node* link=newNode(0);
    //比对，查看交集
    for(int i=0;i<nums1Size;++i)
        for(int j=0;j<nums2Size;++j)
            if(nums1[i]==nums2[j])
                push(link,nums1[i]);                
    //链表里的字符导出
    *returnSize=linkLength(link);
    int* result=(int*)malloc(sizeof(int)**returnSize);
    for(int i=0;i<*returnSize;++i)
        result[i]=pop(link);
    del(link);            
    return result;
}
```