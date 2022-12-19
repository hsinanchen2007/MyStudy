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
#include <math.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int i = 0;
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int sub  = 0;
    unsigned int flag1  = 0;
    unsigned int flag2  = 0;
    unsigned int carry = 0;
    struct ListNode* l3 = NULL; 
    struct ListNode* temp = NULL;

    l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next = NULL;
    temp = l3;

    for(;;)
    {
        if (l1->next != NULL) {
            num1 = l1->val;
            l1 = l1->next;  
        } else if (flag1 == 0 && l1->next == NULL) {
            num1  = l1->val;
            flag1 = 1;
        } else if (flag1 == 1 && l1->next == NULL) {
            
            num1 = 0;
        } 
        
                
        if (l2->next != NULL) {
            num2 = l2->val;
            l2 = l2->next;  
        } else if (flag2 == 0 && l2->next == NULL) {
            num2  = l2->val;
            flag2 = 1;
        } else if (flag2 == 1 && l2->next == NULL) {
            
            num2 = 0;
        } 
         
        if (flag1 == 1 && flag2 == 1)
        {
            sub = num2 + num1;
            l3->val = (sub + carry) % 10; 
            carry = (sub + carry) / 10;
            if (carry == 0) {
                return (temp);
            } else {
                l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                l3 =  l3->next;
                l3->next = NULL;
                l3->val = carry;

                return (temp);  
            }
        } 

        sub = num2 + num1;
        l3->val = (sub  + carry) % 10; 
        carry = (sub + carry) / 10;
        l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3 =  l3->next;
        l3->next = NULL;
        
    }
  

    return (temp);
}
```