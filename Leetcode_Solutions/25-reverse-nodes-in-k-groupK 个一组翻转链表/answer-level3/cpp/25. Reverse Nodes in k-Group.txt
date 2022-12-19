### 解题思路
时间复杂度O(n)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p=new ListNode(0);
        p->next=head;
        head=p;
        while(p){
            ListNode* pi=p;
            for(int i=0;i<k;i++){
                pi=pi->next;
                if(!pi)return head->next;
            }
            for(int i=0;i<k-1;i++){
                ListNode* d=p->next;
                p->next=d->next;
                d->next=pi->next;
                pi->next=d;
                //pi=d;
            }
            for(int i=0;i<k;i++)p=p->next;
        }
        return head->next;
    }
};
```