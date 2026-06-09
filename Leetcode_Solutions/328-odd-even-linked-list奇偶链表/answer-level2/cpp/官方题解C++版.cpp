### 解题思路
官方题解C++版
不需要新建两个链表再合并；在原链表操作即可

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode *odd=head, *even=head->next, *even_bak=head->next;
        int i=1;
        while(even!=NULL&&even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next=even_bak;
        return head;
    }
};
```