此题可以通过循环实现，但个人更偏向使用递归。
- 方法一
递归。每次处理前两个节点。
```c
struct ListNode* swapPairs(struct ListNode* head){
    if(head==0||head->next==0) return head;
    struct ListNode* odd=head, * even=odd->next;
    head=even;
    
    odd->next=even->next;
    even->next=odd;
    odd->next=swapPairs(odd->next);

    return head;
}
```
- 方法二
循环。需要注意处理细节。
```c
struct ListNode* swapPairs(struct ListNode* head){
    if(head==0||head->next==0) return head;
    struct ListNode* odd=head, * even=odd->next;
    head=even;
    do{
        odd->next=even->next;
        even->next=odd;
        odd=odd->next;
        if(odd&&odd->next){
            even->next->next=odd->next;
            even=odd->next;
        }
        else break;
    } while(1);
    return head;
}
```