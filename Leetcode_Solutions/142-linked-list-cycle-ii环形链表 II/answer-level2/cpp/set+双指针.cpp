方法一
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> st;
        while(head!=NULL){
            if(st.count(head)) return head;
            st.insert(head);
            head=head->next;
        }
        return NULL;
    }
};
```
方法二 双指针
两次循环，第一次循环是快慢指针，若链表不是环形，则快指针先到表尾NULL，若是环形，快慢指针会相遇。相遇后将快慢指针之一置到表头head，然后开始第二次循环，此时快慢指针同速移动。当快慢指针再次相遇时到达链表开始入环的第一个节点。
```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //if(head==NULL||head->next==NULL) return NULL;
        ListNode *st=head,*ed=head;
        while(ed!=NULL&&ed->next!=NULL){
            st=st->next;
            ed=ed->next->next;
            if(st==ed) break;
        }
        if(ed==NULL||ed->next==NULL) return NULL;
        st=head;
        while(st!=ed){
            st=st->next;
            ed=ed->next;
        }
        return st;
    }
};
```
