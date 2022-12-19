### 解题思路
1.快慢指针法将链表一分为二，长度上有两种情况：两段相等或者第一段比第二段少1个节点；
2.逆序第二段子链表（#206 反转链表）；
3.将第二段子链表的节点交替插入第一段子链表（实现题目要求的“头尾头尾”式连接）；

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return; //节点数少于3个直接返回
        ListNode* start = new ListNode(0); //定义头节点
        start->next = head;
        ListNode* pre = start, *p = head, *q = head;
        while(q && q->next)
        {
            pre = pre->next; p = p->next; q = q->next->next; //快慢指针
        }
        pre->next = NULL; //分割出两个子链表
        ListNode* r = reverseList(p); //逆序第二段子链表p
        p = head->next; q = r->next; //这里p、q为辅助指针
        while(p && q)
        {
            head->next = r; r->next = p; //交替连接
            head = p; p = p->next; r = q; q = q->next; //四个指针都要后移一位
        }
        head->next = r; //补上最后一个指针
        return;
    }

    ListNode* reverseList(ListNode* head) { //递归法逆序链表
        if(!head || !head->next) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
```