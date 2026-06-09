### 解题思路
I used the longer linklist to store the final result. if it is not long enough, then I will malloc another node to store the carry.
### 代码

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1;
    p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2;
    p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
// p1 and p2 are the node pointer to traversal the while l1 and l2
    int count1 = 0, count2 = 0;

    for(p1 = l1; p1; p1 = p1->next){
        count1++;
    }
    for(p2 = l2; p2; p2 = p2->next){
        count2++;
    }

    if(count1 < count2){
        p1 = l1;
        l1 = l2;
        l2 = p1;
    }
//make sure l1 is longer than l2, because I will use the longer to store final results

    p1 = l1;
    p2 = l2;
//start from the beginning
    int sum, remainder, carry = 0;

    while(1){
        if(carry == 1){
            sum = p1->val + p2->val + 1;
        }
        else{
            sum = p1->val + p2->val;
        }

        if(sum >= 10){
            remainder = sum - 10;
            carry = 1;
        }
        else{
            remainder = sum;
            carry = 0;
        }
        p1->val = remainder;

        if(p1->next && p2->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        else{
            break;
        } // if one of them is null(here it will always be l2 or both),then stop the traversal
    }
//two situations:
    if(p1->next && carry == 1){
        p1 = p1->next;
        while(1){
            if(p1->val+1 == 10){
                p1->val = 0;
                if(p1->next){
                    p1 = p1->next;
                }
                else{
                    struct ListNode *pp;
                    pp = (struct ListNode *)malloc(sizeof(struct ListNode));
                    p1->next = pp;
                    pp->val = 1;
                    pp->next = NULL;
                    break;
                }
            }
            else{
                p1->val += 1;
                break;
            }
        }
    }
    else if(carry == 1){
        struct ListNode *p;
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p1->next = p;
        p->val = 1;
        p->next = NULL;
    }
    return l1;
}
```