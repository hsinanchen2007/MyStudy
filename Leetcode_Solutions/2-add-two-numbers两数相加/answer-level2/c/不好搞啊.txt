struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int length1 = 0;
    int length2 = 0;
    int sum = 0;
    int mod = 10;
    int carry = 0;

    struct ListNode *p1, *p2;
    p1 = l1;
    while(p1){
        length1++;
        p1 = p1->next;
    }
    p2 = l2;
    while(p2){
        length2++;
        p2 = p2->next;
    }

    if(length1 > length2){
        p1 = l1;
        p2 = l2;
    }else{
        p1 = l2;
        p2 = l1;
    }
    while(p1 && p2){
        sum = p1->val + p2->val + carry;
        p1->val = sum % mod;
        carry = sum / mod;
        if(p2->next == NULL){
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    while(p1){
        if(p1->next ==NULL && carry == 1){
            p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p1 = p1->next;
            p1->val = 0;
            p1->next = NULL;
        }else if(p1->next == NULL && carry == 0){
            break;
        }else if(p1->next != NULL && carry == 1){
            p1 = p1->next;
        }else if(p1->next != NULL && carry ==0){
            break;
        }
        sum = p1->val + carry;
        p1->val = sum % mod;
        carry = sum / mod;               
    }
    if(length1 > length2){
        p1 = l1;
    }else{
        p1 = l2;
    }
    return p1;   
}
