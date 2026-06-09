```
struct ListNode* middleNode(struct ListNode* head)
{
    int len = 0;

    struct ListNode* curNode = NULL;
    curNode = head;
    
    while (curNode != NULL) {
        len++;
        curNode = curNode->next;
    }

    len = len / 2;
    curNode = head;
    while (len--) {
        curNode = curNode->next;
    }
    return curNode;
}
```
