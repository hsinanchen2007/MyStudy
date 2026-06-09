### 解题思路
加入一个不含元素的头结点让代码可读性更高

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
        ListNode *head1=new ListNode(-1);
        head1->next=head;
        ListNode *l=head;
        ListNode *r=head;
        ListNode *pre=head1;
        n--;
        while(n--){
            r=r->next;
        }
        while(r->next){
            l=l->next;
            r=r->next;
            pre=pre->next;
        }
        pre->next=l->next;
        return head1->next;
    }
};
```