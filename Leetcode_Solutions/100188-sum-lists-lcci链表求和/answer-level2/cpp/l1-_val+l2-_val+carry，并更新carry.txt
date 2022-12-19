### 解题思路
每次相加都是l1->val+l2->val+carry，并且根据结果更新carry。
需要注意的是最后有可能进位不为0，需要创建一个新节点，该节点的值为carry。

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
        ListNode *h=new ListNode(0);
        ListNode* l3=h;
        int carry=0;
        while(l1&&l2)
        {
            l3->next=new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l2)
        l1=l2;
        while(l1)
        {
            l3->next=new ListNode((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            l3=l3->next;
            l1=l1->next;
        }
        if(carry!=0)
        l3->next=new ListNode(carry);
        return h->next;
    }
};
```