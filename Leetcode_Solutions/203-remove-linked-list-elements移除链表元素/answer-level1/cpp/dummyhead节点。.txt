
由于删除头结点，导致找不到头结点的情况，使用dummyhead。

```
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * cur = head ;
        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * pre = dummyHead ; 
        while(cur != NULL){
            if(cur->val == val){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }else {
                pre = cur;
                cur = cur->next;
            }
        } 
        return  dummyHead->next;
    }
};


```
