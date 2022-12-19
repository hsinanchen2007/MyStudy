![图片1.png](https://pic.leetcode-cn.com/deb3a7780f1b8ad46b9d922e04f24366cf2aff1a9d234f0369c33636c35184fc-%E5%9B%BE%E7%89%871.png)
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret = new ListNode(0);
        ret->next = head;
        ListNode *p=ret, *q = p->next;
        while(p->next&&p->next->next){
            p->next = q->next; p = p->next;
            q->next = p->next; p->next = q;
            p = p->next; q = p->next;
        }
        return ret->next;
    }
};
```
