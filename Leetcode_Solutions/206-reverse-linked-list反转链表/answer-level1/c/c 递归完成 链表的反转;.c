### 解题思路
此处撰写解题思路
  1 step 先由函数到初始链表的倒数第二个节点;
  2 step  当到返回head, 开始执行 head->next->next=head // 反转 head->next=NULL  //切断和head 前一个节点的连系; 
  3 step 返回初始节点的头节点作为 首节点; 
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){  //栈实现递归法;
if(head==NULL || head->next==NULL)  //当为空和仅有一个值时 就直接返回;
return head;
struct ListNode *p;
p=reverseList(head->next) ;//先到尾，往下层去;
head->next->next=head;
head->next=NULL;
return p; 
}

```