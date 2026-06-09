采用归并算法排序链表,主要包括两个关键步骤
- 将链表划分为左右两部分子链表
- 对两个有序链表进行合并

```
//将链表切分为左右两半
void divideList(struct ListNode *head, int n,
                 struct ListNode **leftHead, struct ListNode **rightHead){
    struct ListNode *pre = head;
    int i = 1;
    while(i < n / 2){
        pre = pre->next;
        i++;
    }
    *rightHead = pre->next;
    pre->next = NULL;
    *leftHead = head;
}

//递归合并两个有序链表
struct ListNode *mergeOrderedList(struct ListNode *left, struct ListNode *right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    if(left->val < right->val){
        left->next = mergeOrderedList(left->next, right);
        return left;
    }
    else{
        right->next = mergeOrderedList(left, right->next);
        return right;
    }
}

//归并排序链表
struct ListNode * _sortList(struct ListNode *head, int n){
    if(n <= 1)
        return head;

    struct ListNode *left, *right;
    divideList(head, n, &left, &right);
    left = _sortList(left, n/2);
    right = _sortList(right, n - n/2);
    return mergeOrderedList(left, right);    
}

struct ListNode* sortList(struct ListNode* head){
    int i = 0;
    struct ListNode *p = head;
    while(p != NULL){
        i++;
        p = p->next;
    }
    return _sortList(head, i);
}

```
