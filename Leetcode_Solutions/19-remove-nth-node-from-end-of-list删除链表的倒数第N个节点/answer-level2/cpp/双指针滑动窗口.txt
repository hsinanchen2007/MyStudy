* 方法1思路：先遍历一遍，得到链表长度，再len-n得到要删除的节点位置，再遍历一遍去删除它。
  扫描了两遍列表
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *p = preHead;
        int len = 0;
        if(!p->next) {
            return NULL;
        }
        while(p->next) {
            p = p->next;
            len++;
        }
        len = len - n;
        p = preHead;
        while(len-- && p->next) {
            p = p->next;
        }
        if(p->next && p->next->next) {
            p->next = p->next->next;
        } else {
            p->next = NULL;
        }
        //注意不能返回head，因为可能删除头结点
        return preHead->next; 
    }
};
```
* 方法二思路：设置两个指针，p1和p2间距保持为n， 当p2到达链表末端时，p1刚好到达倒数第n个节点的前一个节点。注意点就是要设置一个无用头结点防止删除头结点，返回时也要返回无用头结点的下一个节点链表。
只扫描了一遍链表。
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *p1 = preHead;
        ListNode *p2 = preHead;
        while(n--) {
            p2 = p2->next;
        }
        while(p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return preHead->next;
    }
};
```
