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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(),*p1=l1,*p2=l2,*mark=ans;
        int v1,v2,carry=0;
        while(p1||p2){
        v1=p1?p1->val:0;
        v2=p2?p2->val:0;
        ListNode* p=new ListNode();
        mark->next=p;
        mark=p;
        mark->val=(v1+v2+carry)%10;
        carry=(v1+v2+carry)/10;
        if(p1)p1=p1->next;
        if(p2)p2=p2->next;
        }
        if(carry){
            ListNode* p=new ListNode();
            mark->next=p;
            p->val=1;
        }
        return ans->next;
    }
};
```