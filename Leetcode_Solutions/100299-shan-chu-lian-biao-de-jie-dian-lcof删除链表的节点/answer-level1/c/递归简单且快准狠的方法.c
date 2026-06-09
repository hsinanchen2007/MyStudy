```
struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        if(head->val!=val){
            return head;
        }
        else{
            return NULL;
        }
    }
    struct ListNode* cur=head;
    if(cur->val==val){
        cur=head->next;
        return cur;
    }
    else{
        head->next=deleteNode(head->next,val);
//进行递归的方式来进行判断返回指向下一个指针的地址
    }
    return cur;
}
```
