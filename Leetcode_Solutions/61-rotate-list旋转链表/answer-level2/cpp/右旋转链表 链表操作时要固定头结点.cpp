### 解题思路
右旋转链表 链表操作时要固定头结点

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int len = 1;
        ListNode* temp = head;
        ListNode* p = head;
        ListNode* q = head;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        int k1 = k%len;
        if(k1 == 0){
            return head;
        }
        while(k1>0){
            q = q->next;
            k1--;
        }
        while(q->next !=NULL){
            p = p->next;
            q = q->next;
        }
        q->next = head;
        head = p->next;
        p->next = NULL;

    return head;
    }
};
```