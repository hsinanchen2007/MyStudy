### 解题思路
找出节点总数
取中值，返回中间节点
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    //找出节点总数
    //取中值（n+1）/2，返回中间节点
    int n=0;
    struct ListNode* p;
    p=head;
    while(p!=NULL)
    {
        p=p->next;
        n+=1;
    }//n为节点总数。
    p=head;
    if(n%2==0)//n分情况
    {
        n=n/2+1;
    }
    else
    {
        n=(n+1)/2;
    }
    for(int i=1;i<n;i++)//找到节点
    {
        p=p->next;
    }
    return p;

}
```