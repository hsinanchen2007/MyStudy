### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    if(count==0) return head;
    count/=2;
    while(count){
        head=head->next;
        count--;
    }
    return head;
}


```