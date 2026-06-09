### 解题思路
//两种思路，第一种：相等就删除，第二种：找到不相等的，再链接到不相等的。第一种适合少数元素重复并且这些元素只重复少次的，第二种适合链表中很多元素都有重复并且有的元素重复多次的


### 代码
```
方法一
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    struct ListNode *p=head,*q=p->next;
    while(q){
        if(p->val == q->val){
            p->next = q->next;
        }else{
            p = q;
        }
        q = q->next;
    }
    return head;
}
```

```
方法二
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    struct ListNode *p=head,*q=p->next;
    while(q){
        if(p->val != q->val){
            p->next = q;
            p = q;
        }
        q = q->next;
    }
    p->next = NULL;    //注意如果最后两个重复的情况，链表尾要指向null
    return head;
}
```