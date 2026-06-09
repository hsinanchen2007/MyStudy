- 方法一
利用两个指针，第一个指针移动一次到下一个节点，第二个指针移动一次到下下个节点。如果该链表是环形链表，那么当两个指针指向同一个节点时，该节点与目标节点的距离（正向）和head节点与目标节点的距离相等。
![412.png](https://pic.leetcode-cn.com/5176fafa8c9a14badd9dc26eded36c7700ac9d238e6336cae47fbbd7143ba609-412.png)
假设快指针和慢指针相遇时慢指针走了k步，由于快指针比慢指针多走了一圈，所以环的长度为k。不难发现相遇节点与目标节点距离为k-(k-p)即为p,head与目标节点的距离也是p。
```c
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast_p=head,*p=head;
    while(fast_p!=0&&fast_p->next!=0){
        fast_p=fast_p->next->next;
        p=p->next;
        if(fast_p==p) break;
    }
    if(fast_p==0||fast_p->next==0) return 0;
    else{
        while(p!=head){
            p=p->next;
            head=head->next;
        }
        return head;
    }
}
```
- 方法二
该方法比较笨。
```c
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==0) return 0;
    struct ListNode *fast_p=head,*p=head;
    while(fast_p!=0&&fast_p->next!=0){
        fast_p=fast_p->next->next;
        p=p->next;
        if(fast_p==p) break;
    }
    if(fast_p==0||fast_p->next==0) return 0;
    else{
        while(1){
            fast_p=fast_p->next;
            if(p==head) return head;
            while(fast_p!=p){
                if(fast_p==head) return head;
                fast_p=fast_p->next;
            }
            head=head->next;
        }
    }
}
```