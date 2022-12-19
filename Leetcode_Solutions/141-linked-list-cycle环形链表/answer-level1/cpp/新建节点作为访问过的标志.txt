新建节点END，节点访问过的标志，将所有访问过的节点指向END
当新访问的节点等于END时就是有环。
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode * END =new ListNode(0);
        ListNode* pre;
        while(head){
            if(head==END) return true;
            pre=head;
            head=head->next;
            pre->next=END;
        }
        return false;
    }
};
```
