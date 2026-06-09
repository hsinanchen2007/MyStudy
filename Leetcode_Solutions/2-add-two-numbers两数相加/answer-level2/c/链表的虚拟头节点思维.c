### 解题思路
虚拟头结点 dummy
https://www.jianshu.com/p/387f4ac21227

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* Node(int val){
    struct ListNode* p;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p ->val = val;
    p ->next = NULL;
    return p;
}



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){


struct ListNode* pt1;
struct ListNode* pt2;
struct ListNode* rl;
struct ListNode* ptmp;
    pt1 = l1;
    pt2 = l2;
    int sum=0;
    int carry=0;
    ptmp = Node(0);
    rl = ptmp;
    while(pt1 || pt2){//
        if(pt1 && pt2){ //都不空
            sum = pt1->val + pt2->val+carry;
            carry = sum/10;
            sum = sum%10;
            ptmp -> next = Node(sum);
            ptmp = ptmp->next;
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
        else if(pt1){//PT1kong
            sum = pt1->val +carry;
            carry = sum/10;
            sum = sum%10;
            ptmp -> next = Node(sum);
            ptmp = ptmp->next;
            pt1 = pt1->next;    
        }
        else if(pt2){//pt2KONG
            sum = pt2->val +carry;
            carry = sum/10;
            sum = sum%10;
            ptmp -> next = Node(sum);
            ptmp = ptmp->next;
            pt2 = pt2->next;    
        }
        
    }
    if(carry){
        ptmp->next = Node(carry);
    }    
    return rl->next;

}
```