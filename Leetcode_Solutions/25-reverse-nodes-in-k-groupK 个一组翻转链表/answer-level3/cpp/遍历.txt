### 解题思路
设一个指针指向当前链表的头节点，设一个指针指向当前的节点，设一个计步器记录当前遍历了几个节点，
遍历链表，每当计步器的值与k相同，就翻转当前节点之前的链表，计步器设回为初始值

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) //如果链表为空，直接返回空
            return NULL;
        if(k==0 || k==1 ||head->next==NULL)//如果k的值为0或者1，或者链表只有一个节点，无需翻转，直接返回原链表
            return head;
        ListNode *now=head;//now指针指向当前的节点
        ListNode *temp; //保存头节点的下一个节点
        ListNode *newhead=new ListNode(-1);//定义一个新的头节点保存翻转后的链表
        ListNode *s=newhead; //s指向新的链表的插入的位置
        ListNode *nexthead; //用来保存当前节点的下一个节点
        int time=1; //设计步器初始值为1
        while(now)
        {
            if(time==k) ///如果time的值与k相等，即有k个数了，就翻转head和now之间的节点，其实就是链表的前插法
            {
                nexthead=now->next;//保存当前节点的下一个节点
                while(head!=nexthead)//前插法操作
                {
                    temp=head->next;
                    head->next=s->next;
                    s->next=head;
                    head=temp;
                }
                while(s->next)//操作完毕后，s指针后移，指向最后的位置为下一次操作的插入位置
                    s=s->next;
                time=1;//计步器的值重新设为1
                now=nexthead;//指向下一个节点
            }
            else//如果time不等于k，即没有k个数，继续遍历，并且time的值+1
            {
                now=now->next;
                time++;
            }
        }
        s->next=head;//上面循环完毕后，头节点可能还有指向节点，此时剩下来的节点个数必定少于k，
                    //不需要翻转，直接接到后面即可
        return newhead->next;
    }
};
```