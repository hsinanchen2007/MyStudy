使用双指针，前一个指针p先往前走n步。此时让另一个指针q位于头结点，之后q和p一起往后走，直至前面的p节点指向尾节点，此时q指向的就是待删除节点，复杂度O（n）。再稍微改一下代码，使得q指向待删除节点的前一个结点就可以啦。
```python3 []
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        p = head
        for i in range(n-1):
            p = p.next
            if p == None: # 如果n的值超过链表长度，则直接返回空指针
                return None
        if p.next == None: # 删除头节点
            return head.next
        else: # 否则，q是待删除节点的前一个节点
            q = head
            p = p.next
            while p.next != None:
                p = p.next
                q = q.next
        p = q.next.next
        q.next = p
        return head
        
```

```C++ []
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = nullptr;
        for(int i = 1; i<n; i++){
            p = p-> next;
            if(p == NULL){
                return NULL;
            }
        }
        if(p->next == NULL){
            return head->next;
        }else{
            p = p->next;
            q = head;
            while(p->next != NULL){
                q = q->next;
                p = p->next;
            }
        }
        
        p = q->next->next;
        q->next = p;
        return head;
    }
};
```

