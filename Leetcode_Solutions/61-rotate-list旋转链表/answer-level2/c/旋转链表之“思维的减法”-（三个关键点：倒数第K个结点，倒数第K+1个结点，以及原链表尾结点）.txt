/***倒数第k个结点做新的链表头结点，倒数第k+1个结点做新链表尾结点，原链表尾结点连接原链表头结点****/
/****引用评论区大佬说的话-->说是循环旋转，但其实本质上是将尾部向前数第K个元素作为头，原来的头接到原来的尾上****/

执行用时 :
4 ms
, 在所有 c 提交中击败了
92.45%
的用户
内存消耗 :
7.4 MB
, 在所有 c 提交中击败了
86.18%
的用户

```
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL)return head;
    
    struct ListNode* p = head;
    struct ListNode* q= NULL;
    struct ListNode* rear= p;// 新的结尾
    
    int count = 1;
    while(p->next != NULL)//遍历整个链表得到长度
    {
        count++;
        p = p->next;
    }
    q = p;//将最后一个元素保存，最后要接到开头
    k%=count;//求余，得实际要旋转次数

  if(count == 1||count == k || k == 0)return head;//当链表长度为k时，或者k为0时原地不动
    p = head;
    int i ;
    for( i = 1; i <= count;i++)//遍历整个链表
    {
        
        if(i == count-k)//倒数的第k+1个元素，用来当做新链表的结尾
        {   
            rear= p;
        }
        else if(i == count-k+1) break;//新的开头 //当找到倒数的第k个数时就跳出，用来当做新链表的开头
        p = p->next;
    } 
    q->next = head;
    head = p;
    rear->next= NULL;//将新的结尾作为空
   
    return head;
```


}