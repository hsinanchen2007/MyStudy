### 解题思路
# 设置两个指针，往前排就好了。这里的else是关键
# 所谓的空指针问题，很有可能是你的代码的逻辑是有问题的。我之前也不相信这一点。后来画了画图排查了一下才加上了else的

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if ( head == NULL ){
        return head;
    }
    struct ListNode* previous_one,*next_one;
    //next_one = (struct ListNode*)malloc(sizeof(struct ListNode));
    previous_one = head;
    next_one=head->next;
    while(next_one){
        if(next_one->val==previous_one->val){
            previous_one->next = next_one->next;
           // free(next_one);
            next_one = previous_one->next;
        }else{
        previous_one = next_one;
        next_one = next_one->next;
        }
    }
    return head;
}
```