只能说c写LeetCode真的是头大
```
/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    struct ListNode* next;
};
/*
给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
删除完毕后，请你返回最终结果链表的头节点。
*/
typedef struct ListNode ListNode;
struct ListNode* removeZeroSumSublists(struct ListNode* head)
{
    ListNode* prehead = (ListNode*)malloc(sizeof(ListNode));  //申请一个节点始终指向head
    prehead->next = head;

    bool hasDel = true;
    while (hasDel) {
        hasDel = false;
        for (ListNode* prenode = prehead; prenode->next != NULL; prenode = prenode->next) {
            int sum = 0;
            for (ListNode* curnode = prenode->next; curnode != NULL; curnode = curnode->next) {
                sum += curnode->val;
                if (sum == 0) {
                    ListNode* destnode = curnode->next;
                    while (prenode->next != destnode) {
                        ListNode* tmpnode = prenode->next;
                        prenode->next = tmpnode->next;
                    }
                    hasDel = true;
                    break;  //跳出当前的第二层循环
                }
            }
            if (hasDel == true) {
                break;
            }
        }
    }
    ListNode* node = prehead->next;
    free(prehead);
    return node;
}
```

