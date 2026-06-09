### 解题思路
将小于x的放到链表1，大于等于x的放到链表2，然后将链表1的尾结点指向链表2的头结点

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* node1_head = new ListNode(0);
        ListNode* node1 = node1_head;
        ListNode* node2_head = new ListNode(0);
        ListNode* node2 = node2_head;
        while(head!=NULL){
            if(head->val<x){
            node1->next = head;
            node1=node1->next;
             }else{
            node2->next=head;
            node2=node2->next;
            }
            head= head->next;
        }
        node2->next = NULL;
        node1->next = node2_head->next;

      return node1_head->next;
    }
};
```