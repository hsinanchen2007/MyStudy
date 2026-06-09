### 解题思路
**head**指向的结点是带数据的，我说结果怎么一直不对

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    // 建立头结点
    struct ListNode *front = (struct ListNode *)malloc(sizeof(struct ListNode));
    front->next = head;
    struct ListNode *p1 = front;
    struct ListNode *p2 = front;
    while(p1->next != NULL) {
        // 仅剩1个节点未遍历
        if(p1->next->next == NULL) {
            p1 = p1->next;
            p2 = p2->next;
            return p2;
        }
        // 仅剩2个节点未遍历
        else if(p1->next->next->next == NULL) {
            p1 = p1->next->next;
            p2 = p2->next->next;
            return p2;
        }
        else {
            p1 = p1->next->next;
            p2 = p2->next;
        }
    }
    return NULL;
}


```