### 解题思路
时间复杂度要求O(n logn)：考虑归并排序、快速排序、堆排序
空间复杂度要求O(1)：不可以用递归

**归并排序**
自底向上排序：两两排序 》》四个四个排序 》》八个八个排序 。。。。。
- 链表无法直接取到其中的结点，每次都需要遍历到开始排序的起始位置(记为h1,h2)，需要记录上次结束的位置
- 需要知道链表的长度，判断需要排序多少次(记每次间隔interval)，最外层循环interval<length
- 在原有头结点之前设置一个辅助结点，便于替换与定位每次排序后的头结点


### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)    //空链表或只有一个结点的链表不用排序
           return head;
        ListNode *p=new ListNode(0);    //原有头结点前的辅助结点
        p->next=head;
        ListNode* h=head;
        int length=0;
        while(h){               //链表长度
            h=h->next;
            length++;
        }
        int interval=1;         //间隔
        h=p;
        ListNode *h1=h,*h2=h;   //归并的两段链表各自的头结点h1,h2
        ListNode *pre=p;  //记录当前排序情况下已排序到的位置，同时pre->next为下一次排序h1的位置
        while(interval<length){
            while(pre->next){   //判断当前是否全部排序完成
                int i=0,j=0;    //分别记录当前归并排序的两段链表的长度（不一定是interval）
                h1=h->next;
                h=h1;
                while(h&&i<interval){
                    h=h->next;
                    i++;
                }
                h2=h;           //如果i<interval,说明构不成两段，其实不用排序
                while(h&&j<interval){
                    h=h->next;
                    j++;
                }               
                int c1=i,c2=j;
                while(c1>0&&c2>0){        //排序过程
                    if(h1->val<=h2->val){
                       pre->next=h1;
                       h1=h1->next;
                       c1--;
                    }else{
                        pre->next=h2;
                        h2=h2->next;
                        c2--;
                    }
                    pre=pre->next;  
                }
                if(c1==0){          //c1,c2中一定有一个为0
                    pre->next=h2;
                    h2=h2->next;
                    pre=pre->next;
                    c2--;
                }else{
                    pre->next=h1;
                    pre=pre->next;
                    c1--;
                }
                while(c1>=1){         //存在一段中的几个数大于另一段中的最大数，直接链入
                    pre=pre->next;
                    h1=h1->next;
                    c1--;
                }
                while(c2>=1){
                    pre=pre->next;
                    h2=h2->next;
                    c2--;
                }
                pre->next=h2;        //链上未排序的部分
                h=pre;               //准备进入下一次排序
            }
            interval*=2;             
            h=pre=p;
        }
        return p->next;
    }
};
```