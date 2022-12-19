### 解题思路
本题比较重要的就是快慢双指针的设定以及while和if语句中条件的判定

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL) return false;
    if(head->next == head) return true;
    struct ListNode *fast = head->next;
    struct ListNode *slow = head;
    while(slow != fast){
        if(fast == NULL || fast->next == NULL){
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
//    while(slow != NULL &&  fast != NULL && fast->next != NULL){
//        fast = fast->next->next;
//        slow = slow->next;
//        if(fast == slow) return true;
//    }
//    return false;
}
```