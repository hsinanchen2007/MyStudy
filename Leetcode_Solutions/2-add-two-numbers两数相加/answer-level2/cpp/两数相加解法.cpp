# solution 1

这题看到就想到从前往后遍历相加即可, 这题要考察的应该是链表的遍历和插入节点吧.
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur_node = head;
        int carry = 0;
        while (l1 || l2) {
            int num = carry;
            if (l1) {
                num += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num += l2->val;
                l2 = l2->next;
            }
            cur_node->next = new ListNode(num % 10);
            carry = num / 10;
            cur_node = cur_node->next;
        }

        if (carry > 0) {
            cur_node->next = new ListNode(carry);
        }
        return head->next;
    }
};
```

# solution 2

solution1中, 是规规矩矩的没去动原来的list, 因此创建节点时会消耗不少时间.
把这块优化一下, 长的那个list拿来用即可.
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur_node = head;
        int carry = 0;
        while (l1) {
            ListNode* temp_node = l1;
            int num = l1->val + carry;
            if (l2) {
                num += l2->val;
                l2 = l2->next;
            }
            l1 = l1->next;
            if (!l1) { // swap
                l1 = l2;
                l2 = NULL;
            }
            cur_node->next = temp_node;
            cur_node = cur_node->next;
            temp_node->val = num % 10;
            carry = num / 10;
        }
        if (carry > 0) {
            cur_node->next = new ListNode(carry);
        }
        return head->next;
    }
};
```