```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 一趟扫描：一共m个节点，删除倒数第n个，先让一个指针
 * 走n步，然后两个指针同时走，慢指针走m-n步，慢指针正
 * 好指向要删除的节点
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;

        // 快指针先走n步
        ListNode *fast = head;
        while(n--) fast = fast->next;

        // 如果删除的是头节点，特殊处理
        if(!fast) return head->next;

        // 慢指针最终指向删除的节点，pre指向要删除节点的前一个节点
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(fast){
            pre = cur;
            cur = cur->next;
            fast = fast->next;

        }

        // 删除
        pre->next = pre->next->next;

        return head;
    }
};
```
