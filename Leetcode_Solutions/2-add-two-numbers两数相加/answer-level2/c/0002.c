```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *fig = NULL;
    head = fig;

    int flag = 0;
    while (1) {
        struct ListNode *temp = (struct ListNode *) malloc(sizeof(struct ListNode));
        temp->next = NULL;

        if (l1 == NULL) {
            if (l2 == NULL) {
                if (flag == 1) {
                    temp->val = 1;
                    if (fig != NULL) {
                        fig->next = temp;
                    }
                    fig = temp;
                }
                break;
            } else {
                int num = l2->val + flag;
                l2 = l2->next;
                if (num >= 10) {
                    flag = 1;
                    num -= 10;
                } else {
                    flag = 0;
                }
                temp->val = num;
                if (fig != NULL) {
                    fig->next = temp;
                }
                fig = temp;
            }
        } else {
            if (l2 == NULL) {
                int num = l1->val + flag;
                l1 = l1->next;
                if (num >= 10) {
                    flag = 1;
                    num -= 10;
                } else {
                    flag = 0;
                }
                temp->val = num;
                if (fig != NULL) {
                    fig->next = temp;
                }
                fig = temp;
            } else {
                int num = l1->val + l2->val + flag;
                l1 = l1->next;
                l2 = l2->next;
                if (num >= 10) {
                    flag = 1;
                    num -= 10;
                } else {
                    flag = 0;
                }
                temp->val = num;
                if (fig != NULL) {
                    fig->next = temp;
                }
                fig = temp;
            }
        }

        if (head == NULL) {
            head = fig;
        }
    }

    return head;
}
```
