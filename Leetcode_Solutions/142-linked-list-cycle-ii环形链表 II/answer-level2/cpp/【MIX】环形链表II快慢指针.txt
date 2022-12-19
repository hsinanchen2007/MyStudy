### 解题思路
1. HsahSet. 使用额外空间
2. 快慢指针. 不使用额外空间

### 代码

**快慢指针**
```c++ []
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Floyd
        if(head == nullptr)
            return head;
        ListNode *pFast = head, *pSlow = head;
        while(pFast != nullptr && pFast->next != nullptr){
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if(pFast == pSlow)
                break;
        }
        if(pFast == nullptr || pFast->next == nullptr)
            return nullptr;
        // 链表中存在环
        ListNode *cur = head;
        while(cur != pSlow){
            cur = cur->next;
            pSlow = pSlow->next;
        }
        return cur;   
    }
};
```
```java []
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null)
            return head;
        // 快慢指针
        ListNode pFast = head, pSlow = head;
        while(pFast != null && pFast.next != null ){
            pFast = pFast.next.next;
            pSlow = pSlow.next;

            if(pFast == pSlow)
                break;
        }

        if(pFast == null || pFast.next == null)
            return null;
        
        ListNode cur = head;
        while(cur != pSlow){
            cur = cur.next;
            pSlow = pSlow.next;
        }

        return cur;
    }
}
```
```python []
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        
        pFast, pSlow, cur = head, head, head
        while pFast != None and pFast.next != None:
            pFast = pFast.next.next
            pSlow = pSlow.next

            if pFast == pSlow:
                break

        if pFast == None or pFast.next == None:
            return None

        while cur != pSlow:
            cur = cur.next
            pSlow = pSlow.next

        return cur
        
```

**额外空间**
```c++ []
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
    ListNode *detectCycle(ListNode *head) {
        // 使用额外空间
        set<ListNode *> rec;
        ListNode *p = head;
        while(p != nullptr){
            if(rec.find(p) == rec.end()){
                rec.insert(p);
                p = p->next;
            }
            else
                return p;
        }
        return nullptr;
    }
};
```