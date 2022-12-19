方法一 迭代
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res=new ListNode(0),*sp=res;
        while(head!=NULL&&head->next!=NULL){
            ListNode* tmp=head->next->next;
            sp->next=head->next;
            head->next->next=head;
            sp=sp->next->next;
            head=tmp;
        }
        if(head!=NULL) sp->next=head;
        else sp->next=NULL;
        return res->next;
    } 
};
```
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *res = new ListNode(0),*tmp = res;
        res->next = head;
        while(tmp->next != NULL && tmp->next->next != NULL) {
            ListNode *start = tmp->next,*end = tmp->next->next;
            tmp->next = end;
            start->next = end->next;
            end->next = start;
            tmp = start;
        }
        return res->next;
    }
};
```
方法二 递归
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=new ListNode(0),*sp=res;
        sp->next=head->next;
        ListNode* tmp=head->next->next;
        head->next->next=head;
        head->next=swapPairs(tmp);
        return res->next;
    } 
};
```
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* tmp=head->next;
        head->next=swapPairs(tmp->next);
        tmp->next=head;
        return tmp;
    }
};
```

