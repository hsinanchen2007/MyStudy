### 解题思路
此处撰写解题思路

### 代码

```cpp
/* 链表相加:
 *      前面是低位  不用考虑对链表逆序
 *
 *      要不要申请额外空间 ？ 最后一个发生进位时需要
 *
 * */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pseudo = new ListNode(0), *tail = pseudo;
        int carry = 0;
        while(l1 || l2){
            int tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            ListNode *l3 = l1 ? l1 : l2;
            l3->val = tmp % 10;
            carry = tmp / 10;
            tail->next = l3;
            tail = l3;
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        if(carry == 1){
            ListNode *last = new ListNode(1);
            tail->next = last;
        }
        ListNode *ret = pseudo->next;
        delete(pseudo);
        return ret;
    }
};
```