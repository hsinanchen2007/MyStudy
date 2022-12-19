### 解题思路
![image.png](https://pic.leetcode-cn.com/fd151eed883ec1695eb9718b39e2e8bae6396d22fbbc449d3c66046f67f90a07-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
       struct ListNode* fast=head,*slow=head;

    while(fast){//当 fast为空时，slow正好指向倒数第 K 个结点
    
        if(k>0){ //若 k 大于0 ，则 flash 先跑
            fast = fast->next;
            k--;
        }else{ //反之，则一起跑
            fast = fast->next;
            slow  = slow->next; 
        }
    }
    return slow;
}
```