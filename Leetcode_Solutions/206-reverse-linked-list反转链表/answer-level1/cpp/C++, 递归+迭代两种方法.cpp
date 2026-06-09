### 解题思路
此处撰写解题思路

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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next == NULL) {
            return head;
        }
        // ListNode* pre = NULL;
        // ListNode* tmp;
        // while (head!=NULL) {
        //     tmp = head->next;
        //     head->next = pre;
        //     pre = head;
        //     head = tmp;
        // }
        // return pre;

        ListNode* pre = NULL;
        return recur(head, pre);

    }

    ListNode* recur(ListNode* head, ListNode* pre) {
        if (head==NULL) {
            return pre;
        }
        ListNode* ans = recur(head->next, head);
        head->next = pre;
        return ans;
    }
};
```