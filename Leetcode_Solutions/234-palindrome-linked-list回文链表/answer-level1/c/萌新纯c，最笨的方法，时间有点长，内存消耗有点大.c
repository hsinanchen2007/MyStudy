### 解题思路
生成一具新的逆序链表，挨个对比，最笨的方法， 高手不要喷

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head)
{
if(head==NULL)return 1;
struct ListNode*ans=head;
struct ListNode*ami=NULL;
struct ListNode*transfer=NULL;
while(ans!=NULL)//生成新的逆序链表
    {
      ami=(struct ListNode*)malloc(sizeof(struct ListNode));
      ami->val=ans->val;
      ami->next=transfer;
      transfer=ami;
      ans=ans->next;
    }
while(head!=NULL)//对比两个链表是不是相同
    {
        if(ami->val!=head->val)
        return 0;
        head=head->next;
        ami=ami->next;          
    }
return 1;
}
```