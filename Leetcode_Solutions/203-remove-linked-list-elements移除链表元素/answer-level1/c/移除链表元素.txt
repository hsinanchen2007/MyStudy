### 解题思路
对整个链表，从链表首元素开始，遍历找到第一个不为目标元素的位置；
从而为pre指针找到其位置。
删除链表元素即在于将该元素的前驱元素使其指向待删除元素的下一元素即可。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
   if(head==NULL)  return head;
   while(head!=NULL){
       if(head->val==val)
       head=head->next;
       else break;
   }
   if(head==NULL) return head;
   struct ListNode *pre=head,*cur=head->next;
   while(cur!=NULL){
    if(cur->val!=val){
         pre=cur;
         cur=cur->next;
    }
    else{
        cur=cur->next;
        pre->next=cur;
    } 
   }
return head;
}
```