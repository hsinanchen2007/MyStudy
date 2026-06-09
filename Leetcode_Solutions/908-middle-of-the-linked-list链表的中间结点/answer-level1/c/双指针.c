- 头节点是个坑，测试用例应该是没有头结点的
- 解法是双指针，即慢指针每次走一个，快指针走两个
- 需要注意的是节点的个数是奇数还是偶数对最后的循环条件是有影响的
```
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *pre, *p;
    pre = head;
    p=pre->next;
    while(p!=NULL&&p->next!=NULL)
    {
        pre = pre->next;
        p = p->next->next;
    }
    if(p!=NULL) pre = pre->next;
    return pre;
}
```
