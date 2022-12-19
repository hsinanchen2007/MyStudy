思路：
1、确定链表长度
2、得到正序时该去掉的是那个结点
3、去掉对应节点，注意2中特殊情况：A、链表只有一个元素  B、要去掉链表的第一个元素

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head->next== NULL)  //A、链表只有一个元素
      return NULL;

    int i = 1;
    struct ListNode* count = head;
    while((count!= NULL) && (count->next!= NULL))
    {
        count=count->next;
        i ++;
        
    }
    int j = i - n ;
    struct ListNode* Find = head;
    
    while(j>=0)
    {
        
        
        if(j == 1)
        {
          Find->next = Find->next->next;
          return head;
        }
        if(j == 0) //B、要去掉链表的第一个元素
        {
            Find = Find->next;  
            return Find;   
        }
        j --;
        if(Find->next!= NULL)
          Find=Find->next;
    }
    return head;
}