### 解题思路
1. 单指针法
2. 快慢指针法

### 代码

```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        if(head == null)
            return null;

        int N = getLength(head);
        int i;
        ListNode p = head;
        if(N % 2 == 1){
            for(i=1; i<=N/2; ++i)
                p = p.next;
        }
        else{
            for(i=1; i<N/2; ++i)
                p = p.next;
        }

        return p;
    }

    private int getLength(ListNode head){
        int n = 1;
        while(head != null){
            n++;
            head = head.next;
        }

        return n;
    }
}
```
```python []
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # 双指针法
        pFast, pSlow = head, head
        while pFast != None and pFast.next != None:
            pFast = pFast.next.next
            pSlow = pSlow.next

        return pSlow
```
```c++ []
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // 快慢指针
        if(head == nullptr)
            return nullptr;
        ListNode *pFast = head;
        ListNode *pSlow = head;
        while(pFast!=nullptr && pFast->next != nullptr){
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};
```