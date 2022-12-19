执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了79.91%的用户
```python []
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        #直接法
        # if head==None or head.next==None: return head
        # i = head
        # head = head.next
        # j = ListNode(0)
        # while i!=None and i.next!= None:
        #     p = i
        #     i = i.next
        #     j.next = i
        #     p.next = i.next
        #     i.next = p
        #     j = p
        #     i = p.next
        # return head
        
        # 递归法
        if not head or not head.next: return head
        next = head.next
        head.next = self.swapPairs(next.next)
        next.next = head
        return next
```
```c++[]
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 直接法
        // ListNode* i=head;
        // ListNode* p = nullptr;
        // ListNode * j = nullptr;
        // if(head == NULL || head->next == NULL) return head;
        // head = head->next;
        // while(i!=NULL && i->next != NULL){
        //     p=i;
        //     i = i->next;
        //     if(j != nullptr){
        //         j->next = i;
        //     }
        //     p->next = i->next;
        //     i->next = p;
        //     j = p;
        //     i = p->next;
        // }
        // return head;
        
        // 递归法
        if(head == NULL or head->next == NULL) return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
```