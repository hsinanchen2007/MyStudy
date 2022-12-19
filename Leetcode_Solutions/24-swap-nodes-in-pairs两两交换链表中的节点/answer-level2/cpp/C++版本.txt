由于需要完成两个链表中的节点之间的交换，所以存储待交换节点的前一个节点的地址是很关键的。本解法中以链表中存在至少三个节点为一般情况，并且在这三个节点中的第一个节点是已经完成了交换后的节点。这时，完成后续两个节点之间的交换就很容易了。那么特殊情况就是
1. 链表中只有一个节点：此时无需处理，直接返回即可；
2. 链表中只有两个节点，且第一个节点直接由head指针指向，此时只需完成两个节点之间的交换即可返回；
3. 当链表中存在不止两个节点，但是由于没有头节点，head指针直接指向的就是第一个节点，所以对于链表中的前两个节点特殊处理，重复2.完成的操作；（或者可以通过增加头节点来将这种情况变成一般的情况）

此后，通过迭代过程即可完成整个交换过程，代码如下：
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        if(cur==NULL) return head;
        if(cur->next==NULL) return head;

        head = swapTwoNode(head);
        cur=head;
        if(cur->next->next==NULL) return head;
        cur=head->next;
        ListNode* tmp = cur;
        while(1){
            if(cur->next==NULL) break;
            if(cur->next->next==NULL) break;
            tmp = cur->next->next;
            cur->next->next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        tmp=NULL;
        return head;
    }
    ListNode* swapTwoNode(ListNode* head);
};

ListNode* Solution::swapTwoNode(ListNode* head){
    ListNode* cur = head->next;
    head->next = cur->next;
    cur->next = head;
    return cur;
}
```
