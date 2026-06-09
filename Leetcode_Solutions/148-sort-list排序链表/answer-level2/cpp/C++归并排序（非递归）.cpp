C++归并排序，非递归，bottom-to-up。按1-2-4-8的长度从头逐一切割链表并归并到已归并好的链表后面，直至merge_len大于链表长度
```c++
class Solution {
 public:
     ListNode* sortList(ListNode* head) {
         if (head == NULL || head->next == NULL)
             return head;
         int list_len = 0;
         ListNode* p = head;
         while (p != NULL)  //计算长度
         {
             list_len++;
             p = p->next;
         }
         ListNode* phead = new ListNode(-1);
         p = phead;
         int merge_len = 1;
         ListNode* p1 = head;
         ListNode* p2 = head;
         ListNode* p3 = head;
         while (merge_len < list_len)
         {
             
             while (p1 != NULL)
             {
                 p2 = list_cut(p1, merge_len);//截取第一段
                 p3 = list_cut(p2, merge_len);//剩余链链首
                 p = merge(p, p1, p2);//把p1、p2合并到p后面
                 p1 = p3;//p1移到剩余链链首
             }
             merge_len = merge_len * 2;//合并长度*2
             p = phead;//一次归并完成后初始化，为下一次准备
             p1 = p->next;//注意，归并一次后，链表头就改变了，不再是head
             p2 = p->next;
             p3 = p->next;
         }
         return phead->next;
     }
     ListNode* list_cut(ListNode* head, int size)
     {
         while (head != NULL && size > 1)
         {
             head = head->next;
             size--;
         }
         if (head != NULL)   //还有节点，则截断
         {
             ListNode* tmp = head->next;
             head->next = NULL;   //截断
             head = tmp;
         }
         return head;        //返回节点
     }
     ListNode* merge(ListNode* p, ListNode* head1, ListNode* head2)  //将head1、head2合并到p后面
     {
         while (head1 != NULL && head2 != NULL)
         {
             if (head1->val < head2->val)
             {
                 p->next = head1;
                 p = p->next;
                 head1 = head1->next;
             }
             else
             {
                 p->next = head2;
                 p = p->next;
                 head2 = head2->next;
             }
         }
         while (head1 != NULL)  
         {
             p->next = head1;
             head1 = head1->next;
             p = p->next;
         }
         while (head2 != NULL)
         {
             p->next = head2;
             p = p->next;
             head2 = head2->next;
         }
         return p;  //返回的是归并完成链表的末尾
     }
 };
```
