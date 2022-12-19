### 解题思路
此处撰写解题思路
（1）找到目标结点；
（2）依次判断该链表结点是否为尾结点、头结点、中间结点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode *tempHead = head;
    struct ListNode *toBeDetelted = NULL;

    if (head == NULL) {
        return head;
    }

    /* 找到待删除的链表结点 */
    while (tempHead != NULL) {
        if (tempHead->val == val) {
            toBeDetelted = tempHead;
            break;
        }
        tempHead = tempHead->next;
    }

    /* 如果链表中没有待删除的元素，直接返回head即可 */
    if (toBeDetelted == NULL) {
        return head;
    }
    
    if (toBeDetelted->next != NULL) {
        /* 如果要删除的结点是非末尾元素 */
        struct ListNode *temp = toBeDetelted->next;
        toBeDetelted->val = temp->val;
        toBeDetelted->next = temp->next;
    } else if (toBeDetelted == head) {
        /* 如果只有一个结点且该结点是头结点 */
        return NULL;
    } else {
        /* 如果是尾结点，且链表结点个数大于1 */ 
        tempHead = head;
        while (tempHead->next->next != NULL) {
            tempHead = tempHead->next;
        }
        tempHead->next = NULL;
    }

    return head;
}
```