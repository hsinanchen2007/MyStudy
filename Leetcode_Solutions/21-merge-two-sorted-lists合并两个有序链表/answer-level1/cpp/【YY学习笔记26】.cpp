### 解题思路
将第二个链表元素合并到第一个链表。
### 知识点
**1.哑结点**可以很便利解决链表只有一个元素的问题，但无法解决链表为空的问题。
**2.INT_MIN**=-2^31，是“int”能表示的最小值。
**3.INT_MAX**=2^31-1,是“int”能表示的最大值。
### 代码

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //思路和合并两个有序数组相似：i指向一个链表，j指向另一个链表。把j链表合并到i链表上。
        if(l1==NULL)return l2;//错误点1：哑结点可便利解决只有一个元素时的情况，但无法解决[]的情况。
        if(l2==NULL) return l1;
        
        ListNode *i,*j,*tmp;
        ListNode firsti(INT_MIN),firstj(INT_MIN);//错误点2:哑结点的赋值取最小。
        firsti.next=l1;
        firstj.next=l2;
        i=&firsti;
        j=&firstj;
        while(i!=NULL&&j!=NULL){
            if(i->next!=NULL&&i->val<=j->val&&i->next->val>=j->val){
            //i->next!=NULL,是为了防止i已经指向链表最后一个元素的情况：因为此时i->next->val不存在。
                tmp=j->next;
                j->next=i->next;
                i->next=j;
                
                i=i->next;
                j=tmp;
            }
            else{
				i=i->next;
            }
        }
        if(j!=NULL){
            i=&firsti;
            while(i->next!=NULL){
                i=i->next;
            }
            i->next=tmp;
        }
        return firsti.next->next;
    }
};
```