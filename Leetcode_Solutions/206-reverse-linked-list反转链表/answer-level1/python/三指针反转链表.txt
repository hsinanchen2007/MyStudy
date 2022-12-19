### 解题思路
每个节点都指向其前一个节点，把最后一个节点作为头节点返回
三个指针，一个当前指针cur，一个指向前一个节点的指针pre，一个指向后一个节点的指针next

### 代码
**c++**
```c++
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
        ListNode *pre = nullptr, *cur = head, *nextNode = nullptr;

        while(cur){
            nextNode = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextNode;
        }

        return pre;
        
    }
};
```

**python**
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head==None or head.next==None:
            return head

        pre = None
        cur = head
        while(cur):
            next_node = cur.next
            cur.next = pre
            pre = cur
            cur = next_node

        return pre
```



