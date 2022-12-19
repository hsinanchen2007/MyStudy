### 解题思路
递归：插入思路，头结点head、待插入的节点insert、待插入的节点的下一个节点tmpNext = insert->next, insert节点指向head即可。比较简单。
### 代码

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *g_ret = NULL;
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    g_ret = NULL;
    struct ListNode *headNext = head->next;
    head->next = NULL;
    Reserve(head, headNext);
    return g_ret;
}
void Reserve(struct ListNode* head, struct ListNode* next) 
{
    if (next == NULL) {
        g_ret = head;
        return;
    }
    struct ListNode *tmpNext = next->next;
    next->next = head;

    Reserve(next,  tmpNext);
}