### 解题思路
设置前后指针，两指针相隔n；当前指针走到队尾，后指针指向倒数第n个的前继；
1、若链表只有一个元素，返回空链表（题意）；
2、若前指针走n步超过了队尾节点，则删除头节点；
3、否则，前后指针相继向前走一步，直到后指针走到队尾；

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) return NULL;
        ListNode *fast, *low;
        fast = low = head;
        for (int i = 0; i < n; ++i){
            fast = fast->next;
        }
        if (fast == NULL) {
            head = head->next;
            return head;
        }
        while (fast->next != NULL){
            fast = fast->next;
            low = low->next;
        }
        low->next = low->next->next;
        return head;
    }
};
```