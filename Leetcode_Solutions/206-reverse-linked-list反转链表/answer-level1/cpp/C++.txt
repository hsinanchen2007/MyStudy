### 解题思路
头插法

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
        ListNode* h=NULL;
        while(head){
           ListNode* p=head;
           head=head->next;
           p->next=h;
           h=p;     
        }
        return h;
    }
};


```