### 解题思路
归并排序的思路：先将一个链表从中间节点分为两个子链表，然后分别对两个子链表进行排序，最后将这两个子链表合并为一个有序链表
寻找链表中间节点的思路：快慢指针，慢指针一次前进一步，快指针一次前进两步
奇数个数节点:1 2 3 4 5，快指针为空时，慢指针刚好指向中间节点
偶数个数节点:1 2 3 4, 快指针为空时，慢指针指向中间节点（不存在真正的中间节点）的前一个节点

这里需要重点理解为什么归并排序的时间复杂度为O(nlogn)

注意: 递归法的时间复杂度为O(nlogn)，空间复杂度为O(logn)

### 递归法代码

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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *preMid, *slow, *fast;
        preMid = slow = fast = head;
        while(fast && fast->next) {
            preMid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 链表拆分
        preMid->next = NULL;
        return mergeTwoList(sortList(head), sortList(slow));
    }

    // 合并两个有序链表
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode *s, *head;
        s = head = new ListNode(0);
        head->next = NULL;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                s->next = l1;
                l1 = l1->next;
            }
            else {
                s->next = l2;
                l2 = l2->next;
            }
            s= s->next;
        }
        s->next = (l1 ? l1 : l2);
        return head->next;
    }
};
```