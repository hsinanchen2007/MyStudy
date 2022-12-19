### 解题思路
 // 思路：一般链表的题目都是双指针法，以避免完全遍历链表好多次
 // 1. 想求倒数第n个节点，那首先的找到它，定义一个快指针，让他提前出发n个节点
 // 2. 然后慢指针再出发，这时候当快指针走到结尾时，慢指针刚好就走到倒数第n个节点，因为快慢指针相差恒定距离n
 // 3. 找到了倒数n，那如果想删除这个节点，则需要将它前一个节点指向它下一个节点，但是单向链表，没法指向它前一个节点，
 // 4. 所以我们就通过定义一个慢指针的前指针pre，来始终指向 慢指针的前一个节点。
 // 所以：三个指针： 快指针，慢指针，慢指针的前一个指针，

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
 // 思路：一般链表的题目都是双指针法，以避免完全遍历链表好多次
 // 1. 想求倒数第n个节点，那首先的找到它，定义一个快指针，让他提前出发n个节点
 // 2. 然后慢指针再出发，这时候当快指针走到结尾时，慢指针刚好就走到倒数第n个节点，因为快慢指针相差恒定距离n
 // 3. 找到了倒数n，那如果想删除这个节点，则需要将它前一个节点指向它下一个节点，但是单向链表，没法指向它前一个节点，
 // 4. 所以我们就通过定义一个慢指针的前指针pre，来始终指向 慢指针的前一个节点。
 // 所以：三个指针： 快指针，慢指针，慢指针的前一个指针，
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }

        ListNode *fast = head; // 快指针，先前进n，
        ListNode *slow = head; // 慢指针，等快指针前进结束后，再一同前进。
        ListNode *preSlow = NULL; // slow指针的前边指针
        
        // 因为题目说n始终有效，所以就可以保证fast走的前n步始终有效，即 fast = fast->next ,而不用判断 fast为空
        for (int i = 0; i < n; i++) {
            fast = fast->next; 
        }

        // 然后快慢前三个指针一起走
        while (fast != NULL) { // fast为空时说明到达末尾，此时 slow指向的就是要删除的节点
            preSlow = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // 删除 slow位置的节点
        if(preSlow == NULL) { // 1. 说明上边的 while循环并未执行，fast已经到达了末尾，那直接删除slow节点，即头节点即可。
            return head->next;
        } else {
            preSlow->next = slow->next;
            slow->next = NULL; // slow指针断开连接
        }
        
        return head;
    }
};
```