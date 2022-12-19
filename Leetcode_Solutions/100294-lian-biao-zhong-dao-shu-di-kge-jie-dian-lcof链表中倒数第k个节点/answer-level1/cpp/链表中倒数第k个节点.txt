### 解题思路

第一点：快满指
第二点：对输入做好容错：k <= 0 或者 链表可能不足k个节点
第三点：边界值要找准（这个可以通过例子）


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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (k <= 0 || !head) {
            return NULL;
        }

        ListNode* fast= head;
        //循环何以继续？ 有下一个，或者往前走了k步
        while (k >= 1 && fast) {
            fast = fast->next;
            k--;
        }

        if (k == 0 && fast == NULL) { //节点个数正好k个
            return head;
        }
        else if (fast == NULL){   //不足k个
            throw new exception;
        }

        ListNode* slow = head;
        //循环何以继续？快指针到底（慢指针指向的便是倒数第k个节点）
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
```