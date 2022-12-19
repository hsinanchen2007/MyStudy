### 解题思路
除了目瞪口呆我还能做什么呢……  
[Two star programming](http://wordaligned.org/articles/two-star-programming)

### 代码

```c
struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode** indirect = &head; 
    //struct ListNode* temp;
    for(; *indirect; indirect = &((*indirect)->next)){
        if((*indirect)->val == val){
            //temp = *indirect;
            *indirect = (*indirect)->next;
            //free(temp);
            break;
        }
    }
    return head;
}
```