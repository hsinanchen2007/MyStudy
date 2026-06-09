### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ptemp1 = l1;
    struct ListNode *ptemp2 = l2;
    int Flag = 0;
    int sum = 0;
    int length1 = 0;
    int length2 = 0;
    struct ListNode * pnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    pnode->next = NULL;
    while(ptemp1 != NULL || ptemp2 != NULL) {
        if (ptemp1 != NULL && ptemp2 != NULL) {
            sum = ptemp1->val + ptemp2->val + Flag;
            if (sum > 9) {
                ptemp2->val = sum - 10;
                ptemp1->val = sum - 10;
                Flag = 1;
            } else {
                ptemp2->val = sum;
                ptemp1->val = sum;
                Flag = 0;
            }
        } else if (ptemp1 == NULL && ptemp2 != NULL) {
            sum = ptemp2->val + Flag;
            if (sum > 9) {
                ptemp2->val = sum - 10;
                Flag = 1;
            } else {
                ptemp2->val = sum;
                Flag = 0;
            }
            length2 = 1;
        } else {
            sum = ptemp1->val + Flag;
            if (sum > 9) {
                ptemp1->val = sum - 10;
                Flag = 1;
            } else {
                ptemp1->val = sum;
                Flag = 0;
            }
            length1 = 1;
        }
        if (ptemp1 != NULL) {
            ptemp1 = ptemp1->next;
        }
        if (ptemp2 != NULL) {
            ptemp2 = ptemp2->next;
        }   
    }
    if (length1) {
        if (Flag) {
            ptemp1 = l1;
            while(ptemp1->next) {
                ptemp1 = ptemp1->next;
            }
            pnode->val = Flag;
            ptemp1->next = pnode;
        }
        return l1; 
    } else if (length2) {
        if (Flag) {
            ptemp2 = l2;
            while(ptemp2->next) {
                ptemp2 = ptemp2->next;
            }
            pnode->val = Flag;
            ptemp2->next = pnode;
        }
        return l2;
    } else {
        if (Flag) {
            ptemp2 = l2;
            while(ptemp2->next) {
                ptemp2 = ptemp2->next;
            }
            pnode->val = Flag;
            ptemp2->next = pnode;
        }
        return l2;
    }
}
```