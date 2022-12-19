1.第一次遍历，知道链表有count个节点
2.n=count-n;此时的n为要删除的节点的前一个节点
3.第二次遍历，找到第n个。改变其next指向，删除头节点做特殊情况处理。
4.问题解决。

核心代码如下：
while(current!=NULL)
    count++;
n=count-n;
current=head;
if(n==0)
{
    head=current->next;
    free(currnt);
}
else
{
    for(int i=1;i<n;i++)
        current=current->next;
    temp=current->next;
    current->next=current->next->next;
    free(current->next);
}

return head;