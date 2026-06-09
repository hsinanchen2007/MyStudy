/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 *总体思路：从head->next开始，逐个节点和head进行比较，如果值比head小，则进行插入。
 *实现过程：
 *1.引入dummy节点，初始时dummy节点的next指向NULL。引入next节点记录head节点的下一个节点。
 *2.第一次循环将head节点插入到NULL指针之前（即将head节点和NULL指针进行交换），更新head节点：head = next。
 *（循环开始后，链表被分成两条，dummy连接排序后的链表，head为另一条未排序链表的头结点）
 *3.之后每次循环，均head->val和dummy链表的节点逐个进行比较，若head->val小，则进行插入（节点交换）操作。该过程引入cur节点记录插入位置的上一个节点。
*/

struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = NULL;

    while (head != NULL) {
        struct ListNode *cur = dummy;
        struct ListNode *next = head->next;

        while (cur->next != NULL && cur->next->val < head->val) {
            cur = cur->next;
        }

        head->next = cur->next;
        cur->next = head;
        head = next;
    }

    return dummy->next;
}