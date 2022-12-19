算法题：重思想；



1 方法一：两次遍历
思路：要删除倒数第N个节点，也就是说删除正数第（length-N+1）个节点，要找到（length-N）个节点.
   第一次遍历求出链表长度，第二次遍历找到第（length-N）个节点，将后面的节点删除。
   需要特殊考虑的情况是，只有一个结点的情况。（可以提前添加一个头节点：官方做法就是这样，也可以找到后分情况讨论）。


1.1分情况讨论
```
class Solution {
public:
    int getLength(ListNode* head)
    {
        int length=0;
        ListNode* p=head;
        while(p!=NULL)
        {
            length++;
            p=p->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head;
        int length=getLength(head);
        int j=length-n;

        if(j==0)//这个是为了只有一个节点的情况
        {
            return head->next;
        }
        int i=1;
        while(i<j)
        {
            i++;
            p=p->next;
        }
        ListNode* q=p->next;
        p->next=q->next;
        return head;
    }
};
```

1.2 添加一个头节点

```
class Solution {
public:

    int getLength(ListNode* head)
    {
        int length=0;
        while(head!=NULL)
        {
            length++;
            head=head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        int length=getLength(head);
        length-=n;
        ListNode* first=dummy;
        int i=0;
        while(i<length)
        {
            i++;
            first=first->next;
        }
        first->next=first->next->next;
        return dummy->next;


    }
};
```

方法二：双指针法（按照官方题解说的那样）
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* first=dummy;
        ListNode* second=dummy;
        for(int i=0;i<n+1;i++)//中间要隔N个数字，就要走N+1步
        {
            second=second->next;
        }

        while(second!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        first->next=first->next->next;
        return dummy->next;
    }
};
```
