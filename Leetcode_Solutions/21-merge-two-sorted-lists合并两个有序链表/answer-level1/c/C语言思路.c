### 解题思路
新手上路，记录一下自己的想法。
参考标准题解的迭代方法，关键点有三：
1 跟踪指针的应用，将排序好的节点按顺序连接。
2 while循环；while(l1!=NULL&&l2!=NULL) 需要配合p1->next =(l1== NULL) ? l2 :l1;
  //此时L1和L2中的一个可以是非空的，因此将非空列表连接到合并列表的末尾。（困扰最多的地方）
  或者可以改成
   while(l1!=NULL||l2!=NULL)
        if(l1==NULL) p1->next=l2;
        if(l2==NULL) p1->next=l1;
//会带来空指针错误，慎用。
3 空指针带来的运行错误。
       p2=(struct ListNode*)malloc(sizeof(struct ListNode));
       p1=(struct ListNode*)malloc(sizeof(struct ListNode));
4 p2=p1;保留头结点，因为之后P1在不断变化，若缺少这一步，只会输出最后一步的结果。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 
 *     struct ListNode *next;
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p1,*p2;
    p2=(struct ListNode*)malloc(sizeof(struct ListNode));
    p1=(struct ListNode*)malloc(sizeof(struct ListNode));
    p2=p1;
           
    while(l1!=NULL&&l2!=NULL)
    {

        if(l1->val<l2->val) 
        {
            p1->next=l1;
            l1=l1->next;
        }
        else 
        {
            p1->next=l2;
            l2=l2->next;
        }
        p1=p1->next;  
    }
    p1->next =(l1== NULL) ? l2 :l1;//此时L1和L2中的一个可以是非空的，因此将非空列表连接到合并列表的末尾。


    return p2->next;
}

```