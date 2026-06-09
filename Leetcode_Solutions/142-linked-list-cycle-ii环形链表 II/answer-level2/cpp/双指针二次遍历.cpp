定义快慢指针，遍历一遍，寻找相交节点；然后将快指针从头重新遍历，此时快慢指针每次都走一步；再次相交则为环形起始节点。
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p, H(-1);
        for(H.next=head, p=&H; p && p->next; head=head->next){
            p=p->next->next;
            if(p==head) break;
        }
        if(!p || !(p->next)) return NULL;
        for(p=&H; (p=p->next) != (head=head->next););
        return p;
    }
};
```
