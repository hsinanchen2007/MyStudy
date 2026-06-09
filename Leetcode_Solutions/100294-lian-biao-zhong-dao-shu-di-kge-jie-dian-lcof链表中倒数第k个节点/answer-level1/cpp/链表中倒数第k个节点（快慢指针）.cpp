### 解题思路
典型的快慢指针，一个在前，一个在后

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
public: //典型的快慢指针
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==nullptr||k==0) return NULL;
        ListNode *p=head,q=head;
        while(k--) p=p->next; //一开始写了个while(k-1)。。头疼
        while(p){
            p=p->next;
            q=q->next;
        }
        return q;
    }
};
```