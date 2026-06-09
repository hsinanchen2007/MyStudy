C，4ms，击败99.81%。

直接上代码!!!

思路很简单。首先短路返回，在空链表或者只有一个元素的链表的情况下，节省创建变量和循环判断。

接下来主要就是主循环直接放个true，优于判断当前链表游标。内层取翻转结束节点时如果遇到NULL直接返回，而不是用break，这样也会少一个程序步。

然后是`expendable`变量，它可以直接作为翻转次数的循环变量，在获取结束节点时，已经增加到和k相等的值，那么就可以刚好拿来递减循环翻转，这样也可以节省把结束节点赋值给一个变量的程序步。

```
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    
    if ( head == NULL || head->next == NULL ) return head;
    
    struct ListNode * newHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    newHead->next = head;
    
    struct ListNode * rHead = head;
    struct ListNode * cNode = head;
    struct ListNode * sNode = head;
    struct ListNode * preNode = newHead;
    
    while ( true )
    {
        int expendable = 0;
        for ( ; expendable < k; ++expendable )
        {
            if ( cNode == NULL ) return newHead->next;
            cNode = cNode->next;
        }
        
        struct ListNode * tmpNode;
        while ( --expendable > 0 )
        {
            tmpNode = sNode->next;
            sNode->next = tmpNode->next;
            tmpNode->next = rHead;
            rHead = tmpNode;
        }

        preNode->next = rHead;
        preNode = sNode;
        rHead = sNode = cNode;
    }
    
    return newHead->next;
    
}
```
