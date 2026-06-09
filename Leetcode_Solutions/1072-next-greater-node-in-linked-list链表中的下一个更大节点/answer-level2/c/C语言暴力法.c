```
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    struct ListNode *p = head;

    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    int *result = malloc(sizeof(int) * count);              //测得链表元素个数，并申请空间

    count = 0;
    p = head;
    while(p)
    {
        struct ListNode *curr = p;
        
        int max = p->val;
        while(curr && curr->val <= max)
            curr = curr->next;                          //找到距离当前节点最近且大于当前节点的位置
        
        if(curr == NULL && max == p->val)               //如果不存在，则为零
            max = 0;
        else
            max = curr->val;

        result[count++] = max;
        p = p->next;
    }
    *returnSize = count;
    return result;
}
```
