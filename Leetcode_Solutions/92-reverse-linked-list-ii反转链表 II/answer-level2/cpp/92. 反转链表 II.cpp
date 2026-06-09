```
/*无注释版
    start end
      |  |      
输入: 1->2->3->4->5->NULL, m = 2, n = 4


输出: 1->4->3->2->5->NULL
     |         | 
     start     end
链表移动不是位置，链表位置是固定不变，修改是内部指针
执行用时 : 4 ms, 在Reverse Linked List II的C++提交中击败了99.11% 的用户
*/
class Solution3 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(NULL ==head ||NULL ==head->next ||m>=n)
      {
          return head;
      }
      //寻找地m-1 m个位置
      ListNode* end=head;
      ListNode* start=NULL;
      ListNode dump(-1);
      dump.next=head;
      start=&dump;
      

      for(int i=1;i<m;i++)
      {
       start=end;
       end=end->next;
      }//m=1时候 start没有移动

      ListNode* temp=NULL;
     for(int i=m;i<n;i++)
     {
        temp=end->next;
        end->next=end->next->next;
    
       temp->next=start->next;//
       start->next=temp;
     }

     return dump.next;

    }
};

```