旋转实际是循环链表，但达到循环的最终结果就行，不必真正循环。变化的只是链表的表头和表尾。将原表首表尾首相连，若链表长为length，每循环一个length，就恢复原表。循环k次，则实际移动了k%length步，新表尾位置在第length-k%length-1的位置，该节点的next为表首，从该位置将链表一分为二，后半部分拼接到原表头即可。
```
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k<=0||!head)return head;
    struct ListNode *p = head;
    int length = 1;
    while(p->next){
        p=p->next;
        length++;
    }
    p->next = head;
    p = head;
    for(k=length - k%length-1;k>0;k--){
        p = p->next;
    }
    head = p->next;
    p->next = NULL;  

    return head;
}
```

