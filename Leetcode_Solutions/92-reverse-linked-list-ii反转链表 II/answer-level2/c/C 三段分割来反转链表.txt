```
void reverseList(struct ListNode* left)
{
    struct ListNode* head = left;
    struct ListNode* p = left->next;
    struct ListNode* q = NULL;
    head->next = NULL;
    
    while (p != NULL) {
        q = p->next;
        p->next = head;
        head = p;
        p = q;
    }
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* left = head;
    struct ListNode* right = NULL;
    
    struct ListNode* revLeft = NULL;
    struct ListNode* revRight = NULL;
    
    int cnt = 1;
    //find the node that number m-1
    while (cnt++ < m - 1 && left != NULL) left = left->next;
    
    if (m == 1) {
        revLeft = head;
    } else if (left != NULL && left->next != NULL) {
        revLeft = left->next;
    }

    revRight = revLeft;
    cnt = m;
    while (cnt++ < n && revRight != NULL) revRight = revRight->next;

    //find the second list
    if (revRight != NULL) {
        right = revRight->next;
        revRight->next = NULL;
    }

    //左右节点倒换
    reverseList(revLeft);
    
    struct ListNode* tmp = revLeft;
    revLeft = revRight;
    revRight = tmp;

    if (m == 1) {
        head = revLeft;
        revRight->next = right;
    } else {
        left->next = revLeft;
        revRight->next = right;
    }
    return head;
}
```
