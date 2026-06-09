
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode** a = (struct ListNode**)malloc(sizeof(struct ListNode*)*10000);
    // a为结构体指针数组，保存每个节点的地址
    int len=0;
    // len 为链表长度
    struct ListNode* p = head;
    while(p != NULL) // 遍历链表，将节点地址保存在数组a中，求出链表长度
    {
        a[len] = p;
        p = p->next;
        len++;
    }
    int tar = len - n;// tar 为要删除的结点所对应的数组下标
    if(tar == 0) // 如果要删除头结点
    {
        p = head -> next;
        free(head);
        return p;
    }
    else
    {
        tar--; // 得到删除结点的前一个结点的数组下标
    }
    // 删除结点
    p = a[tar]->next;
    a[tar]->next = p->next;
    free(p);
    //释放a
    free(a);
    return head;
}
```