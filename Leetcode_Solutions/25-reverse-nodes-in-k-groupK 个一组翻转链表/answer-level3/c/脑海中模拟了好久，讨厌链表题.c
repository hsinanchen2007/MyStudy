### 解题思路
1. 找到要反转的那个组
2. 翻转（算法同反转单链表）
3. 组与组的衔接

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode dummy = { // 哨兵节点
        .next = head,
    };            
    struct ListNode *k_pre = &dummy; // 指向当前待反转组的前一个节点
    struct ListNode *k_start = head; // 指向当前待反转组的第一个节点
    
    struct ListNode *itor = head; // 游标指针，遍历整个链表
    int idx = 0; // 记录游标指针移动的距离
    while(itor) {
        struct ListNode *next = itor->next;
        if (idx == k-1) {
            struct ListNode *k_end = itor;
            // reserve selected group [k_start, k_end]
            struct ListNode *cur = k_start;
            struct ListNode *pre = NULL;
            while(cur != next) {
                struct ListNode *temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            k_pre->next = pre;
            k_pre = k_start;
            k_start->next = next;
            k_start = next;
        }
        idx = (idx+1)%k;
        itor = next;
    }
    return dummy.next;
}
```