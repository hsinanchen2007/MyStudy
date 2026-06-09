#  删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

```
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
```
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

<hr>

##  解：

```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;//存放链表长度
        ListNode *p=head;
        while(p)//计算链表长度
        {
            count++;
            p=p->next;
        }
        p=head;
        if(count==1) return {};//链表只有一个元素
        else if(count-n==0) return head->next;//要删除的元素是第一个
        else 
        {
            for(int i=1;i<count-n;i++)
            {
                p=p->next;
            }
            p->next=p->next->next;
        }
        return head;
    }
};
```

##  进阶：双指针

```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h=new ListNode(0);
        h->next=head;
        ListNode *p=h;
        ListNode *k=h;
        if(head->next==NULL) return {};
        for(int i=0;i<=n;i++)
        {
            k=k->next;
        }
        while(k)
        {
            p=p->next;
            k=k->next;
        }
        p->next=p->next->next;
        return h->next;
    }
};
```

