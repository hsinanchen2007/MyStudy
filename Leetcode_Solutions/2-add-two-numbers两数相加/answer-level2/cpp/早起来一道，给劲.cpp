### 解题思路
时间：o(n), 空间o(1)
小学生都会的算术。但是这种做法要注意链表的建立，插入，考察基本功。

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
        int carry = 0;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *res = new ListNode(0), *temp, *resEnd;
        res->next = NULL;
        resEnd = res;
        while(p1!=NULL&&p2!=NULL){
            temp = new ListNode(0);
            temp->val = (p1->val+p2->val+carry)%10;
            resEnd->next = temp;
            resEnd = temp; 
            carry = (p1->val+p2->val+carry)/10;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1!=NULL){
            temp = new ListNode(0);
            temp->val = (p1->val+carry)%10;
            resEnd->next = temp;
            resEnd = temp; 
            carry = (p1->val+carry)/10;
            p1 = p1->next;
        }
        while(p2!=NULL){
            temp = new ListNode(0);
            temp->val = (p2->val+carry)%10;
            resEnd->next = temp;
            resEnd = temp; 
            carry = (p2->val+carry)/10;
            p2 = p2->next;
        }
        if(carry){
            temp = new ListNode(0);
            temp->val = carry;
            resEnd->next = temp;
            resEnd = temp; 
        }
        resEnd->next = NULL;
        return res->next;
    }
};
```