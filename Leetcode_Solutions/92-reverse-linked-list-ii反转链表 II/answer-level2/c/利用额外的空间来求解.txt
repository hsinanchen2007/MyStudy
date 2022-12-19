1. 先记录下，第m个和第n+1个的地址，并且利用数组记录下中间第m个到第n个节点的val
2. 再将数组中的元素由最后一个到第一个的顺序分别赋值个第m个到第n个节点的val
```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
//借助额外的空间
    int len = n-m+1;
    int i=1,count=0;
    struct ListNode *p, *q;
    p=q=head;
    int arr[len];
    while(i<=n) {
        if(i==m)
            p = q;
        if(i>=m)
        {
            arr[count]=q->val;
            count++;
        }
        q = q->next;
        i++;
    }
    while(p!=q)
    {
        p->val = arr[count-1];
            count--;
        p = p->next;
    }
    return head;
}
```

