### 迭代:
1.让最后一位链表的next指向它前一位
2.让他指向他的前一位
3.原来的第一位指向NULL
4.将改变NEXT的节点的next值保留下来
**正着写**:
- 确定大致思路:
##### 1.从首位开始,记录它后两位节点
##### 2.令该节点的下一位的指针域指向该节点
##### 3.转移操作对象(p=下一位节点指针变量名)
- 确定判断边界:p,p->next(用于翻转),p->next->next(用于记录原先节点的后两位节点)
- 剔除边界外情况(鲁棒性)
- 确定操作范围(对第一位至倒数第二位进行操作)
- 对操作范围外的节点进行操作
```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p=head;
        if(!p||!p->next)
        return p;
        if(!p->next->next)
        {   head=p->next;
            p->next->next=p;
            p->next=NULL; 
            return head;
        }
        ListNode *ind=p->next->next;//存储p->next->next
        ListNode *change=p->next;//被改变节点
        ListNode *Head;
        p->next=NULL;
        while(p&&change&&ind)
        {
            change->next=p;//令2指向1
            p=change;
            change=ind;
            ind=change->next;
        }
        change->next=p;
        return change;
    }
};

```
