简单的想法
```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *p, *q ,*r, *q_tail; //p:奇链链尾， q:偶链链头， q_tail：偶链链尾，r:下一个要加入奇链的节点。
        p = head;
        if(!p) return head;
        q = p->next;
        if (!q || !q->next)
            return head;
        q_tail = p->next;

        while(q_tail && q_tail->next)
        {
            r = q_tail->next; // 偶链链尾后一定是未加入奇链的奇节点。
            
            q_tail->next = r->next; // 偶链加入一个新节点，或偶或空
            r->next = q;            // 奇节点的next连接到偶链链头
            p->next = r;            // 奇节点加入奇链
            
            q_tail = q_tail->next;  // 偶链尾指针更新
            p = p->next;            // 奇链尾指针更新
        }
        return head;
    }
};
```