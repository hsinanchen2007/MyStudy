### 解题思路
为防止头结点也会被逆转，设置一个哑结点dummy，dummy.next=head。
pre指向m-1处的结点，ppre指向m处的结点，p指向m+1处的结点。
for循环就是始终把m处后一个结点（p）头插到pre后，ppre不用动，每次改变p结点即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m==n) return head;
    struct ListNode *pre,*ppre,*p;
    struct ListNode dummy;
    dummy.next=head;
    pre=&dummy;
    int i=1;
    while(i<m)
    {
        i++;
        pre=pre->next;
    }
    ppre=pre->next;
    for(i=0;i<n-m;i++)
    {
        p=ppre->next;
        ppre->next=p->next;//取下p结点
        p->next=pre->next;//头插到pre后面
        pre->next=p;
    }
    return dummy.next;
}
```