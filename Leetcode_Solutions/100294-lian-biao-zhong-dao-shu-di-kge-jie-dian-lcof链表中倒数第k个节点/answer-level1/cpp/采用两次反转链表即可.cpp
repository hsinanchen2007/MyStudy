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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* ans = NULL;
        ListNode* temp;
        temp = head;
        while(temp!=NULL){
           ListNode* tmp;
           tmp = temp->next;
           temp->next = ans;
           ans = temp;
           temp = tmp;
        }
        ListNode* pre = NULL;
        ListNode* res = ans;
        while(k--){
            ListNode* tmp;
            tmp = res->next;
            res->next = pre;
            pre = res;
            res = tmp;
        }
        return pre;
    }
};
```