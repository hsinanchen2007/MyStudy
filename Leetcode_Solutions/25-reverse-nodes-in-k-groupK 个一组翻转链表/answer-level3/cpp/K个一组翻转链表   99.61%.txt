C++,20ms,击败99.61%；
思路就是直接用循环实现，先计算出总链表的长度，然后判断需要实现多少次K的反转。
需要注意的是：
1. 当k=2或者反转到剩余两个节点的时候，我们可以直接终止链表的反转循环，因为这便于处理我们的头结点和尾结点的连接。
2. 这是一种懒人思路，毕竟直接算出了链表长度和k的关系。所以循环过程并不难。新手求建议0.0
```
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode phead(0);
        phead.next = head;
        ListNode* pre = &phead;
        ListNode* last = head;
        int count = 0;
        while(last) {
            count++;
            last = last->next;
        }
        count /= k;//循环次数
        while(k!=1 && count--) {
            int n = k;
            ListNode* q = head->next;
            ListNode* p = head;
            ListNode* r;
        //实现链表翻转
            while(n>2) { 
                r = q->next;
                q->next = p;
                p = q;
                q = r; 
                n--;
            }//最后一个位置是q，前面是p
            //尾连接
            head->next = q->next;
            q->next = p;//最后一步的链表反转
            //头连接
            pre->next = q;
            
            pre = head;//更新前驱节点和头结点
            head = head->next;
        }
        return phead.next;
    }
};
```
