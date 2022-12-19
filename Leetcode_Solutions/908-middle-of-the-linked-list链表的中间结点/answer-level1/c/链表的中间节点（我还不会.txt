输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* p;
    struct ListNode* q;
    p = q = head;
    while(1)
    {
        if(p->next == NULL)
        {
            break;
        }
        else if(p->next->next == NULL)
        {
            q = q -> next;
            break;
        }
        else
        {
            p = p->next ->next;
            q = q->next;
        }
    }
    return q;
}
```