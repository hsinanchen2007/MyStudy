### 解题思路1
思路1、双指针，一前一后，另外一个临时指针用来存储当前节点的下一个节点，确保不会断开连接。

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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre,*cur,*pNext;
        pre = NULL;
        cur = head;
        pNext = NULL;
        while(cur != NULL)
        {
            pNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = pNext;
        }
        return pre;
    }
};
```
### 解题思路2
思路2、递归。确实很骚气，建议看其他大佬的图解。关键在于通过head->next->next来指回去，然后因为指回去了，所以head->next也就没有用了，保持置空一直到最后。
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *cur = NULL;
        cur = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
    }
};
```
