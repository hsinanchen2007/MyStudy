方法一
将所有需要反转的点反转完再连接
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* cur = head, *pre = NULL; //记录每次反转的两个节点
        while(--m > 0) {
            pre = cur; 
            cur = cur->next; 
            --n;
        }
        ListNode *st = pre, *ed = cur,*tmp = NULL; //st,ed记录连接点
        pre = cur; //翻转开始的节点
        cur = cur->next;
        while(--n > 0) { //反转
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        if(st != NULL)  st->next = pre; //第一个节点不为翻转开始点时
        else head = pre; //第一个节点为翻转开始点时
        ed->next = cur;
        return head;
    }
};
```
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(-1),*cur = dummy, *pre = NULL; //cur,pre记录每次反转的两个节点
        dummy->next=head; //dummy哑节点
        while(m-- > 0) {
            pre = cur; 
            cur = cur->next; 
            n--;
        }
        ListNode *st = pre, *ed = cur,*tmp = NULL; //st,ed记录连接点
        pre = cur; //翻转开始的节点
        cur = cur->next;
        while(n-- > 0) { //反转
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        st->next = pre; //连接
        ed->next = cur;
        return dummy->next;
    }
};
```
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(-1),*pre=dummy,*cur=NULL;
        dummy->next=head;
        n=n-m;
        while(--m>0) pre=pre->next;
        cur=pre->next;
        ListNode *st = pre, *ed = cur,*tmp = NULL; //st,ed记录连接点
        pre = cur; //翻转开始的节点
        cur = cur->next;
        while(n-->0){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        st->next = pre; //连接
        ed->next = cur;
        return dummy->next;
    }
};
```
方法二 
每反转一对点连接一次
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(-1),*pre=dummy;
        dummy->next=head;
        n=n-m;
        while(--m>0) pre=pre->next; //eg 1->2->3->4->5->NULL, m = 2, n = 4 pre指向1
        ListNode* cur=pre->next; //cur指向2
        while(n-->0){
            ListNode* tmp=cur->next; //记录3->4->5->NULL
            cur->next=tmp->next; //断开2->3,实现2->4
            tmp->next=pre->next; //断开3->4,实现3->2
            pre->next=tmp; //断开1->2,实现1->3， 一次循环后变为1->3->2->4->5->NULL，下次循环原理相同
        }
        return dummy->next;
    }
};
```



