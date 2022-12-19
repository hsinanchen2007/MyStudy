### 解题思路
双指针的典型应用，在草稿纸上比划比划就清楚了

### 代码

```c

int kthToLast(struct ListNode* head, int k){
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
    return slow->val;
}
```