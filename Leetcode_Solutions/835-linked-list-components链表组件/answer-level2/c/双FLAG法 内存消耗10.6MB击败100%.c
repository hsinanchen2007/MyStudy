在一个属于集合节点的后面出现一个不属于集合的节点则组件个数加一，所以需要订立两个flag标志来观察当前指针和上一个节点是否属于集合，如果`flag2==0&&flag1==1`**前一个不属于集合而后一个属于集合**，则给sum加一。     在链表的结尾处要做特殊处理，如果最后一个节点属于集合，也要给sum加一。
  
如：0 1 0（0代表属于集合）则组件个数为2
0 1 1 组件个数为1

```
int numComponents(struct ListNode* head, int* G, int GSize){
    int sum=0,i,flag1=1,flag2=1;//flag1==1代表当前指针的节点不在集合内，flag2==1代表当前指针的前一个节点不在集合内
    struct ListNode *p=head;
    while(p)
    {
        for(i=0;i<GSize;i++)
        {
            if(p->val==G[i])
            {
                break;
            }
        }
    flag2=flag1;
    if(i==GSize) flag1=1;
    else flag1=0;
    if(flag2==0&&flag1==1) sum++;
    p=p->next;
    }
    if(flag1==0)sum++;
    return sum;
    

}
```

