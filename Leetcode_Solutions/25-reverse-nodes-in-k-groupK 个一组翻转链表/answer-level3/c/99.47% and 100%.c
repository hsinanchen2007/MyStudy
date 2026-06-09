### 解题思路
一次循环，解决！

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

//head后面是否还有k个节点（包括head）
bool hasKNodes(ListNode *head, int k){
    if(!head) return 0;
    ListNode *p = head;
    while(p && k--){
        p = p->next;

    }
    return k<=0;
}


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    ListNode rs = {0, head};
    ListNode *start, *p, *temp;
    start = &rs;
    p = rs.next;
    //核心是将p后面的节点插入start后面
    while(hasKNodes(p, k)){
        //需要更新k-1个节点
        int j = k-1;
        while(j--){
            temp = p->next;
            p->next = temp->next;
            temp->next = start->next;
            start->next = temp;
        }
        //更新start位置
        start = p;
        //更新p位置
        p = p->next;
    }
    return rs.next;
}
```