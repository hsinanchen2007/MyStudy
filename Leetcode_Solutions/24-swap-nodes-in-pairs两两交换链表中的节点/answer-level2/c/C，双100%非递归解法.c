### 解题思路
定义一个整数i用来判断能不能两两交换；
三个移动指针，一个新头指针。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    int i=0;
    struct ListNode* p=head->next;
    struct ListNode* pre=head;
    struct ListNode* first=head->next;//
    struct ListNode* pHeadNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHeadNode->next=head;//设置一个空的头结点
    while(p!=NULL)
    {   
        if(i%2==0)  //判断链表元素能否成为一对，能则交换
        {
            pre->next=p->next;
            p->next=pre;
            pHeadNode->next=p;
            p=pre->next;
            pHeadNode=pHeadNode->next;
            i++;
        }
        else{ //不能成为一对，向后推；
            p=p->next;
            pre=pre->next;
            pHeadNode=pHeadNode->next;
            i++;
        }
    }
    return first;
}
```