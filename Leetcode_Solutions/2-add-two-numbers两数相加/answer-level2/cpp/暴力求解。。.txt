1. 各自相加，进位另存（注意要连接，所以要保留存在链表节点）；
2. 相加结束，连接到同一链表；
3. 判断进位，直到为零；
4. 增加节点，保存多余进位。


```
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
        if (!l1){
            return l2;
        }
        if (!l2){
            return l1;
        }
        ListNode* l3 = new ListNode(0);
        int acc = 0;
        l3 = l1;
        while (l1->next&&l2->next){
            int temp = l1->val + l2->val + acc;
            l1->val = temp % 10 ;
            acc = temp / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        int temp = l1->val + l2->val + acc;
        l1->val = temp % 10;
        acc = temp / 10;

        if (l2->next){
            l1->next = l2->next;
        }
        if (l1->next&&acc != 0){
            l1 = l1->next;
            while (l1->next){
                int temp = l1->val + acc;
                l1->val = temp % 10;
                acc = temp / 10;
                l1 = l1->next;
            }
            int temp = l1->val + acc;
            l1->val = temp % 10;
            acc = temp / 10;
        }
        if (acc != 0){
            ListNode* l4 = new ListNode(acc);
            l4->next = NULL;
            l1->next = l4;		
        }
        return l3;
    }
};
```
