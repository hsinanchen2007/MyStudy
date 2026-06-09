/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode *n1 = l1;
    struct ListNode *n2 = l2;
    int len1 = 0;
    int len2 = 0;
    while (n1) {
        n1 = n1->next;
        len1++;
    }
    n1 = l1;
    while (n2) {
        n2 = n2->next;
        len2++;
    }
    n2 = l2;
    int lenmax = len1 > len2 ? len1 : len2;
    lenmax++;
    int *ary1 = malloc(lenmax * sizeof(int));
    int *ary2 = malloc(lenmax * sizeof(int));
    memset(ary1, 0, lenmax * sizeof(int));
    memset(ary2, 0, lenmax * sizeof(int));
    for (int i = 0; i < len1; i++) {
        ary1[i] = n1->val;
        n1 = n1->next;
    }
    n1 = l1;
    for (int i = 0; i < len2; i++) {
        ary2[i] = n2->val;
        n2 = n2->next;
    }
    n2 = l2;
    int left = 0;
    for (int i = 0; i < lenmax; i++) {
        ary1[i] += ary2[i] + left;
        if (ary1[i] >= 10) {
            ary1[i] %= 10;
            left = 1;
        } else {
            left = 0;
        }
        printf(" %d ", ary1[i]);
    }
    n1 = len1 > len2 ? l1 : l2;
    struct ListNode* ret = n1;
    if (ary1[lenmax - 1]) {
        int i = 0;
        struct ListNode* tmp = NULL;
        while (n1) {
            n1->val = ary1[i];
            tmp = n1;
            n1 = n1->next;
            i++;
        }
        struct ListNode* add = malloc(sizeof(struct ListNode));
        add->val = ary1[i];
        add->next = NULL;
        tmp->next = add;
    } else {
        int i = 0;
        while (n1) {
            n1->val = ary1[i];
            n1 = n1->next;
            i++;
        }
    }
    return ret;
}