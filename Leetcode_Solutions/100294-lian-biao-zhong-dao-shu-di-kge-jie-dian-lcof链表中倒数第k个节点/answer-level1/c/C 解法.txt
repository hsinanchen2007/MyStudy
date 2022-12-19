# 代码：
```
struct ListNode* getKthFromEndrecursion(struct ListNode* head, int*k){
    if(head == NULL) return head; 
    
    struct ListNode *node = getKthFromEndrecursion(head-> next, k);
    
    if(!*k) return node;
    else (*k)--;
    
    return head;

}
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    return getKthFromEndrecursion(head, &k);
}
```
