

```
方法1：循环找最后一个节点
typedef struct ListNode NODE_S;

struct ListNode* rotateRight(struct ListNode* head, int k){
    NODE_S *ptailNode = NULL;
    NODE_S *pLastNode = NULL;
    NODE_S *pNewHead = NULL;
    int j = 0;
    int i = 0;

    if (head == NULL) {
        return NULL;
    }

    if (k == 0 || head->next == NULL) {
        return head;
    }

    ptailNode = head;
    while(ptailNode != NULL) {
        j++;
        ptailNode = ptailNode->next;
    }

    i = k%j;
    ptailNode = head;
    pNewHead = head;
    while (i > 0) {
        pLastNode = pNewHead;
        ptailNode = pNewHead->next;
        while (ptailNode && ptailNode->next != NULL) {
            pLastNode = pLastNode->next;
            ptailNode = ptailNode->next;
        }

        i--;
        pLastNode->next = NULL;
        ptailNode->next = pNewHead;
        pNewHead = ptailNode;
    }

    return pNewHead;
}

方法2：找到后面第k个节点，然后遍历到最后直接截断

typedef struct ListNode NODE_S;

struct ListNode* rotateRight(struct ListNode* head, int k){
    NODE_S *pLastNode = NULL;
    NODE_S *pNode = NULL;
    NODE_S *pNewHead = NULL;
    int j = 0;
    int i = 0;

    if (head == NULL) {
        return NULL;
    }

    if (k == 0 || head->next == NULL) {
        return head;
    }

    pNode = head;
    while(pNode != NULL) {
        j++;
        pNode = pNode->next;
    }

    i = k%j;
    pLastNode = head;
    pNode = head;
    while (i > 0) { // 找到后面第k个偏移节点
        pLastNode = pLastNode->next;
        i--;
    }

    //遍历到最后倒数第k个节点，直接当做头节点
    while (pLastNode->next != NULL) {
        pNode = pNode->next;
        pLastNode = pLastNode->next;
    }

    pLastNode->next = head;
    pNewHead = pNode->next;
    pNode->next = NULL;

    return pNewHead;
}
```