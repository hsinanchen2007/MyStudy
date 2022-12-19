先将问题简化为两个节点的互换
先在链表前面添加一个哑节点，将这个哑节点的地址保存下来，最终它的next值作为返回值。
假设有4个节点 1 2 3 4 
通过temp、head、next代表前节一节点（1）、当前节点（2）与后一节点（3），最终交换当前节点（2）与后一个节点（3）的位置。1 3 2 4 
然后将temp移动至节点（2），head移动至节点（4）的位置再次开启循环。
循环终止条件为当前节点为空或者下一节点为空（即链表节点个数为奇数，最后只有一个一节点，不用交换）
注意如果链表只有一个节点的情况。

```
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode temp_node = {0,NULL};
    struct ListNode* temp = &temp_node;//哑节点
    struct ListNode* next = NULL;
    struct ListNode* res = temp;
    temp->next = head;
    //如果只输入[1]，不会进入下面的while循环。如果没有一开始连接到首个节点，将会输出temp->next即为NULL;
    while(head && head->next)//偶数个head=NULL;奇数个则head->next=NULL;
    {
        //交换两个节点位置，并将节点联通
        next = head->next;
        temp->next = next;
        head->next = next->next;
        next->next = head;
        //移动至下一个需要交换的节点
        temp = head;
        head = head->next;
    }
    return res->next;
}
```
