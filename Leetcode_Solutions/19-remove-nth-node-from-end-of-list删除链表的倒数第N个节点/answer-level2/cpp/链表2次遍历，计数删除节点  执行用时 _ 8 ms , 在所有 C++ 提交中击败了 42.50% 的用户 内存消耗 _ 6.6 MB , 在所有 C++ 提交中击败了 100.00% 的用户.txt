### 解题思路
就是遍历一次链表，并记录有几个元素，在for到删除元素之前删除元素。返回链表头。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        if(n == 0) return head;
        int len = 0;
        ListNode* h = head;
        while(head->next != NULL){
            len++;
            head = head->next;
        }
        ListNode* he = h;
        for(int i = 0; i < len+2-n; i++){
            if(len+1-n == 0) return h->next;
            if(i == len-n){
                ListNode* delL = he->next;
                he->next = delL->next;
                delete delL;
                break;
            }else he = he->next;
        }
        return h;
    }
};
```