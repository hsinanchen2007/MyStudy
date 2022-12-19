### 解题思路
把题目给的两个集合转换成链表，链表节点记录着储存的元素和其数量
对比两个链表，找出交集元素，按元素的最小个数存入交集中（交集也是个链表）
交集转换成数组

题目：交集中允许出现重复的元素数，重复的次数是给出的两个集合中，出现较少的次数
比如
A={1,2,3,4,5,5,5,5,5,6} 5个5
B={1,2,3,4,5,5,5,6,6,6,6,6,} 3个5
交集中就应该有3个5,取数量最少的。

时间多，但是节省空间
![image.png](https://pic.leetcode-cn.com/df92e139c333e20039c395de5ded4b0bc98375d212b4a98c5cd0e010b08a9e21-image.png)

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//--------------------------------------------------------集合存在链表中
typedef struct NodeLink{
    int data;
    int times;
    struct NodeLink* next;
}NodeLink;

NodeLink* newNodeLink(int Data,int Times)
{
    NodeLink* n=(NodeLink*)malloc(sizeof(NodeLink));
    n->data=Data;
    n->times=Times;
    n->next=0;
    return n;
}
void pushLink(NodeLink* Head,int Data)
{
    NodeLink* n=Head->next;
    while(n!=0)
        if(n->data==Data)
        {
            n->times=n->times+1;
            return;
        }
        else
            n=n->next;
    n=newNodeLink(Data,1);
    n->next=Head->next;
    Head->next=n;;
}
void delLink(NodeLink* Head)
{
    while(Head!=0)
    {
        NodeLink* n=Head;
        Head=Head->next;
        free(n);
    }
}
//--------------------------------------------------------交集存在表中
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* newNode(int Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
void push(Node* Head,int Data)
{
    Node* n=newNode(Data);
    n->next=Head->next;
    Head->next=n;
}
int pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    int result=n->data;
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
//--------------------------------------------------------解答
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    NodeLink* n1=newNodeLink(0,0);
    NodeLink* n2=newNodeLink(0,0);
    for(int i=0;i<nums1Size;++i)pushLink(n1,nums1[i]);
    for(int i=0;i<nums2Size;++i)pushLink(n2,nums2[i]);

    Node* head=newNode(0);
    for(NodeLink* iter1=n1->next;iter1!=0;iter1=iter1->next)
        for(NodeLink* iter2=n2->next;iter2!=0;iter2=iter2->next)
            if(iter1->data==iter2->data)
                for(int i= iter1->times < iter2->times ? iter1->times : iter2->times;i>0;--i)
                    push(head,iter1->data);
    delLink(n1);
    delLink(n2);

    *returnSize=length(head);
    int* result=(int*)malloc(sizeof(int)**returnSize);
    for(int i=0;i<*returnSize;++i)
        result[i]=pop(head);
    del(head);
    return result;
}


```