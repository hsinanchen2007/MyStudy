方法一：头插法
```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL) return NULL;
    struct ListNode *curr = head;
    struct ListNode *dummy, *pPrev;
    dummy = (struct ListNode*)malloc(sizeof (struct ListNode));
    struct ListNode *pNext;
    int i = 0;

    dummy->next = head;
    pPrev = dummy;    
    for (i=0; i<m-1; i++)   //leetcode上的链表head节点好像就是首元节点？控制循环次数使pPrev指向待反转的链表段起始位置
    {
        if (pPrev->next != NULL)
        {
            pPrev = pPrev->next;
        }
    }
    curr = pPrev->next;

    for (i=m; i<n; i++)
    {
        if (curr->next != NULL)
        {
            pNext = curr->next;
            curr->next = pNext->next;
            pNext->next = pPrev->next;
            pPrev->next = pNext;
        }
    }


    return dummy->next;
}
```

方法二：改变指针指向后，再进行链表的连接
```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL) return NULL;
    struct ListNode *curr = head;
    struct ListNode *conn, *tail, *temp;
    struct ListNode *pre = NULL;
    int i = 0;

    for (i=0; i<m-1; i++)
    {
        if (curr->next != NULL)
        {
            pre = curr;
            curr = curr->next;
        }
    }
    conn = pre;
    tail = curr;

    for (i=m; i<n+1; i++)   //这里要比头插法多循环一次
    {
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }

    if (conn != NULL)   //m==1时，conn==NULL
    {
        conn->next = pre;
    }
    else
    {
        head = pre;
    }

    tail->next = curr;  //curr是否为空不影响，无需防护


    return head;
}   
```
