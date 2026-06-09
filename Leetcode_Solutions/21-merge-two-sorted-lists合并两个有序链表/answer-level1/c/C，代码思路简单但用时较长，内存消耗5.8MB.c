### 解题思路
本题最大的问题就在于两个链表并非带头结点的链表，这就造成了头指针指定的麻烦。因此本题先确定头指针，然后比较两个链表中值得大小，采用头插法建立。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l,*pre,*p;     //l新有序链表的头指针，指向合并后的第一个元素；pre指向待插入元素的前一个元素；p指向插入元素
    if(l1==NULL){   //前两个if，用来判断其中一个链表为空，返回另一个；两个都空返回空
        return l2;
    }
    if(l2==NULL){   
        return l1;
    }
    if(l1->val<=l2->val){   //用来找出第一个元素，即头指针指向元素
        p=l1->next;
        l1->next=NULL;
        l=l1;
        pre=l;
        l1=p;
    }
    else{
        p=l2->next;
        l2->next=NULL;
        l=l2;
        pre=l;
        l2=p;
    }
    while(l1&&l2){
        if(l1->val<=l2->val){
            p=l1->next;
            l1->next=NULL;
            pre->next=l1;
            pre=pre->next;
            l1=p;
        }
        else{
            p=l2->next;
            l2->next=NULL;
            pre->next=l2;
            pre=pre->next;
            l2=p;
        }
    }
    if(l1){
        pre->next=l1;
    }
    if(l2){
        pre->next=l2;
    }
    return l;
}


```