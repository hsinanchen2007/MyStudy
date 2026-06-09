不改动原有结构体的next指针，只是把数都取出来，然后反向赋值回去。
复杂度：
空间：O(n)
时间：O(n)
执行用时:0 ms，在所有 C 提交中击败了100.00%的用户
内存消耗:6.2 MB，在所有 C 提交中击败了100.00%的用户
```c
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL)
    return NULL;
    struct ListNode* p0;
    int len=0;
    int point=0;
    for(p0=head;p0!=NULL;p0=p0->next)
        len++;
    int *nums=calloc(len,sizeof(int));
    for(p0=head;p0!=NULL;p0=p0->next,point++)
        nums[point]=p0->val;
    point--;
    for(p0=head;p0!=NULL;p0=p0->next,point--)
        p0->val=nums[point];
    return head;
    
}
```
