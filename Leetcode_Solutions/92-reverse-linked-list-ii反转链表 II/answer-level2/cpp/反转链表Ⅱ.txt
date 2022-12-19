### 解题思路
为了将反转完成的子链表添加到原链表中，需要一个指向m-1处的指针，和m处的指针；分两种情况考虑：1.当m=1时，第n个位置的节点作为新链表的头节点；2.当m!=1时，第m-1位置的节点应接上第n个位置的节点；在以上两种情况中，链表反转完毕后，都需要将m处节点接上n+1处节点。
思路:
定义指向m-1、m处节点的指针：子链表头的前一个节点——subheadprev; 子链表的尾节点——tail; 定义用于反转链接的三个工具指针：指向当前节点的指针——p;指向前一个节点的指针——t;指向后一个节点的指针——q;
1.判断链表非空
2.找到m-1处；
3.判断m是否等于1；若m!=1可以赋值subheadprev和t，并更新p；否则subheadprev和t都是NULL，p就是头节点；
4.赋值tail；
5.反转：判别条件是N-m>-1；（因为循环一开始p在m处，应该反转n-m+1次；
6.判断subheadprev是否为NULL，若不为NULL，将其next指针指向t;否则将链表头节点更新为t;
7.更新tail，将其next指向p;


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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL)
            return head;//判断是否为空链表
        ListNode* p=head;
        ListNode* q=NULL;
        ListNode* t=NULL;
        ListNode* subheadprev=NULL;
        ListNode* tail=NULL;
        for(int i=m;i>2;i--){
            p=p->next;//寻找到m号节点的前一个节点；
        }
        //如果m!=1,待反转子链表之前至少有一个节点不为空，存在指向子链表头的节点，且链表的头节点不需要改变，
        if(m!=1){
            t=p;
            p=p->next;
            subheadprev=t;
        }
        tail=p;
        //反转子链表
        for(;n-m>-1;n--){
            q=p->next;
            p->next=t;
            t=p;
            p=q;
        }
        //子链表前是否存在不为空的节点
        if(subheadprev!=NULL){
            subheadprev->next = t;
        }else {
            head=t;
        }
        tail->next=p;
        return head;
    }
};
```