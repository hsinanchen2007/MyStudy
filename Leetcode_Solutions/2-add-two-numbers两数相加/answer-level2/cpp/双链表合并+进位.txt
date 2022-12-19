### 解题思路
此题考点：
（1）双链表合并，先并行合并，然后遇到某一个或者两个链表结束，退出循环，单独为未完成链表连接在新链表后面，考虑不想修改原链表结构，这里new很多新的结点；
（2）进位，进位问题用一个int型的进位符，每次计算通过sum % 10的余数留下作为结点val，sum / 10作为进位符数据，传递给下一个结点用于sum的计算，sum = head1->val + head2->val + level，最后考虑一下如果两个链表均截止了但是有一个进位，需要判断一下进位符是否有数据。

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
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* head3 = new ListNode(0);
        ListNode* p = head3;
        int level = 0;
        while(head1 != NULL && head2 != NULL){
            int sum = head1->val + head2->val + level;
            ListNode* t = new ListNode(sum % 10);
            level = sum / 10;
            p->next = t;
            p = p->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1 == NULL && head2 != NULL){
            int sum = head2->val + level;
            ListNode* t = new ListNode(sum % 10);
            level = sum / 10;
            p->next = t;
            p = p->next;
            head2 = head2->next;
        }
        while(head1 != NULL && head2 == NULL){
            int sum = head1->val + level;
            ListNode* t = new ListNode(sum % 10);
            level = sum / 10;
            p->next = t;
            p = p->next;
            head1 = head1->next;
        }
        if(level != 0){
            ListNode* t = new ListNode(level);
            p->next = t;
        }
        return head3->next;
    }
};
```