```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        ListNode *p = head;
        ListNode *r = p->next;
        ListNode *q = r->next;
        int len = 3;
        while(q->next != NULL){
            len += 1;
            q = q->next;
        }
        for(int i = 0; i < len/2; i ++){
            q->next = r;
            p->next = r->next;
            r->next = NULL;
            
            p=p->next;
            q = r;
            r = p->next;
        }
        return head;
    }
};

//   解题思路：
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//            |
//            |   从第二个结点开始, 交换第二个结点2与后续结点3, 4, 5的位置
//            V
//   1 -> 3 -> 4 -> 5 -> 2 -> NULL
//             |
//             |   交换第三个结点4 与 后续结点5, 2的位置
//             V
//   1 -> 3 -> 5 -> 2 -> 4 -> NULL 
//             |
//             |   当交换的次数等于 len/2 的时候结束（len是链表的长度）
//             V
//          return head;

/**
 *这并不是什么好方法, 仅仅是share一下.
 *毕竟一开始就要遍历一遍链表, 把q指针定位到尾结点了.
 *然后又要再次遍历一半.
 *所以时间复杂度为O(1.5n)=O(n); 用了三个指针, 所以空间复杂度为三个指针O(1).
 *相比官方解法还是慢了一点.
 */
```
