> 将两个链表合并并排序

思路：先连接，再选择排序  
执行用时 :4 ms, 在所有 C 提交中击败了94.72%的用户  
内存消耗 :7.4 MB, 在所有 C 提交中击败了84.02%的用户  

用选择排序的话，效率应该不是很高，但是竟然通过了？！难以置信！  

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)return l2;
    if(l2 == NULL)return l1;
    struct ListNode *currItem = l1;
    while(currItem->next){
        currItem = currItem->next;
    }
    currItem->next = l2;
    currItem = l1;
    struct ListNode *nextItem = NULL;
    while(currItem){
        int temp;
        nextItem = currItem->next;
        while(nextItem){
            // 这里并没有交换节点，而是交换了值
            if(currItem->val > nextItem->val){
                temp = currItem->val;
                currItem->val = nextItem->val;
                nextItem->val = temp;
            }
            nextItem = nextItem->next;
        }
        currItem = currItem->next;
    }
    return l1;
}
```

看了看题解，有同学这么做，不失为一种好方法： 
思路：加了一个头节点，将l2中的节点和l1的节点比较，若l2的节点小于l1的节点，则将l2插在前面，l2换下一个节点，l1也换下一个节点。

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)return l2;
    if(l2 == NULL)return l1;
    if(l1 ==NULL && l2 == NULL)return l1;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    // pre是p1的前一个节点, temp来记住p2的下一个节点
    struct ListNode *pre, *p1, *p2, *temp;
    head->next = l1;
    pre = head;
    p1 = pre->next;
    p2 = l2;
    while(p2){
        if(p1 == NULL){
            pre->next = p2;
            break;
        }
        if(p2->val <= p1->val){
            temp = p2->next;
            p2->next = pre->next;
            pre->next = p2;
            // 注意这里！p2是插入进了l1中，看似在p1前，但实际上l1变长了。
            // 所以下一个p1还是当前的值，所以要重新将p1指向p2，然后下面才可以执行p1 = p1->next  
            p1 = p2;
            p2 = temp;
        }
        pre = p1;
        p1 = p1->next;
    }
    return head->next;
}
```
