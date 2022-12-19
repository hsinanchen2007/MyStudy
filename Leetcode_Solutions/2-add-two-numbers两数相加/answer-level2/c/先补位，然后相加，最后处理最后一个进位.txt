/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL && l2 == NULL) return NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode *p, *q;
    p = l1;
    q = l2;
    int length1 = 0;
    int length2 = 0;
    while(p->next){
        p = p->next;
        length1++;
    } 
    while(q->next){
        q = q->next;
        length2++;
    } 
    if(length1 > length2){
        int diff = length1 - length2;
        while(diff){
            struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
            t->val = 0;
            t->next = NULL;
            q->next = t;
            q = q->next;
            diff--;
        }
    }
    if(length1 < length2){
        int diff = length2 - length1;
        while(diff){
            struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
            t->val = 0;
            t->next = NULL;
            p->next = t;
            p = p->next;
            diff--;
        }
    }
    
    struct ListNode *pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre->val = 0;
    pre->next = NULL;
    struct ListNode *cur = pre;
    int carry = 0;
    p = l1;
    q = l2;
    while(p && q){
        int sum = 0;
        sum = p->val + q->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        
        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val = sum;
        s->next = NULL;
        cur->next = s;
        cur = cur->next;
        p = p->next;
        q = q->next;
    }

    if(carry == 1){
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = 1;
        t->next = NULL;
        cur->next = t;
    }
    return pre->next;
    
}