记录一个前指针，当前指针和下一个指针进行交换位置，具体看代码，注释写得很详细。
```python []
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        result = ListNode(0)
        result.next = head
        pre = result
        p = head
        while p and p.next:
            q = p.next        # 取下一个
            p.next = q.next   # 保留剩下的
            q.next = p        # 交换
            pre.next = q  # 接上前面的
            pre = p       # 新的前一个位置
            p = p.next    # 移动当前位置
        pre.next = p   # 接上最后剩下的单个节点
        return result.next
```
```C++ []
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * result = new ListNode(0);
        ListNode *pre = result, *p, *q;
        result->next = head;
        p = head;
        while (p!=NULL && p->next!=NULL) { // 还有连续的两个
            q = p->next;       // 取下一个
            p->next = q->next; // 接下后续的
            q->next = p;       // 交换完成
            pre->next = q;     // 接上之前的
            pre = p;           // 前指针后移
            p = p->next;       // 当前指针后移
        }
        pre->next = p;     // 接上可能剩下的单个节点
        return result->next;
    }
};
```
