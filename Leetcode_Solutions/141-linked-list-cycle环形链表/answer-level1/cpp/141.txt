```
//第一遍；do while
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        do
        {
            if(fast == NULL || fast->next == NULL)
                return false;
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);
        return true;
    }
};
//while
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while ( fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;    
            if ( slow == fast )
                return true; // 若横跨步数不同还能有机会在同一位置则证明该链表中有环
        }
        return false;
    }
};
//第二遍：set
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::set<ListNode*> nset;
        while(head)
        {
            if(nset.count(head))
                return true;
            else
                nset.insert(head);
            head=head->next;
        }
        return false;
    }
};
```