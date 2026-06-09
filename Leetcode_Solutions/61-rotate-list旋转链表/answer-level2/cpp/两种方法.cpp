方法一
```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* p=head,*t=head;
        int hsize=0;
        while(p!=NULL){
            p=p->next;
            hsize++;
        }
        if(hsize==0||k%hsize==0) return head; 
        int m=hsize-k%hsize-1,n=k%hsize-1;
        while(m-->0) head=head->next;
        ListNode* tp=head->next,*res=tp; //eg 1->2->3->4->5->NULL, k = 2, tp记录4->5->NULL
        head->next=NULL; //作用：1->2->3->NULL
        while(n-->0) tp=tp->next; //找到5
        tp->next=t; //作用：将5连到1, 4->5->1->2->3->NULL
        return res;
    }
};
```
方法二
```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* p=head;
        int hsize=0;
        while(p->next!=NULL){
            p=p->next;
            hsize++;
        }
        hsize++;
        if(k%hsize==0) return head;
        p->next=head; //表尾连到表头 eg 1->2->3->4->5->NULL 5连到1
        int m=hsize-k%hsize;
        while(m-->0) p=p->next;
        ListNode* res=p->next; //记录新表头4->
        p->next=NULL;//3->NULL
        return res;
    }
};
```
