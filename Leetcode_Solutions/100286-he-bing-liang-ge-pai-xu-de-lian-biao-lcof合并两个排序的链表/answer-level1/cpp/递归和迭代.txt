递归和迭代两种方法都能做
递归：
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL)
            return NULL;
        else if(l1&&l2==NULL)
            return l1;
        else if(l2&&l1==NULL)
            return l2;
        if(l1->val<l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```
迭代：
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*head= new ListNode(-1),*h=head;
        while(l1&&l2){
            if(l1->val<l2->val){
                h->next = l1;
                l1 = l1->next;
            }else{
                h->next=l2;
                l2 = l2->next;
            }
            h=h->next;
        }
        if(l1)
            h->next=l1;
        if(l2)
            h->next=l2;
        return head->next;
    }
};
```